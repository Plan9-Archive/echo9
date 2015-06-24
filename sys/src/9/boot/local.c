/* 
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <u.h>
#include <libc.h>
#include <../boot/boot.h>

static char diskname[64];
static char *disk;
static char **args;

void
configlocal(Method *mp)
{
	char *p, *inibootdisk;
	int n;

	inibootdisk = getenv("bootdisk");
	if(*sys == '/' || *sys == '#'){
		/*
		 *  if the user specifies the disk in the boot cmd or
		 * 'root is from' prompt, use it
		 */
		disk = sys;
	} else if(strncmp(argv0, "dksc(0,", 7) == 0){
		/*
		 *  on many mips arg0 of the boot command specifies the
		 *  scsi logical unit number
		 */
		p = strchr(argv0, ',');
		n = strtoul(p+1, 0, 10);
		sprint(diskname, "#w%d/sd%dfs", n, n);
		disk = diskname;
	} else if(mp->arg){
		/*
		 *  a default is optionally supplied when the kernel is made
		 */
		disk = mp->arg;
	} else if(inibootdisk != nil && *inibootdisk)
		/* plan9.ini overrides default from config file */
		disk = inibootdisk;
	else if(bootdisk != nil && *bootdisk){
		/*
		 *  an environment variable from a pc's plan9.ini or
		 *  from the mips nvram or generated by the kernel
		 *  is the last resort.
		 */
		disk = bootdisk;
	}

	/* if we've decided on one, pass it on to all programs */
	if(disk) {
		bootdisk = disk;
		setenv("bootdisk", bootdisk);
	}
}

int
connectlocalkfs(void)
{
	int i, pid, fd, p[2];
	char partition[64];
	char *dev;
	char **arg, **argp;
	Dir *d;

	if(stat("/boot/kfs", statbuf, sizeof statbuf) < 0)
		return -1;

	dev = disk ? disk : bootdisk;
	snprint(partition, sizeof partition, "%sfs", dev);
	fd = open(partition, OREAD);
	if(fd < 0){
		strcpy(partition, dev);
		fd = open(partition, OREAD);
		if(fd < 0)
			return -1;
	}
	/*
	 * can't do this check -- might be some other server posing as kfs.
	 *
	memset(buf, 0, sizeof buf);
	pread(fd, buf, 512, 0);
	close(fd);
	if(memcmp(buf+256, "kfs wren device\n", 16) != 0){
		if(strstr(partition, "/fs"))
			print("no kfs file system found on %s\n", partition);
		return -1;
	}
	 *
	 */
	d = dirfstat(fd);
	close(fd);
	if(d == nil)
		return -1;
	if(d->mode&DMDIR){
		free(d);
		return -1;
	}
	free(d);

	print("kfs...");
	if(pipe(p)<0)
		fatal("pipe");
	switch(pid = fork()){
	case -1:
		fatal("fork");
	case 0:
		arg = malloc((bargc+5)*sizeof(char*));
		argp = arg;
		*argp++ = "kfs";
		*argp++ = "-f";
		*argp++ = partition;
		*argp++ = "-s";
		for(i=1; i<bargc; i++)
			*argp++ = bargv[i];
		*argp = 0;

		dup(p[0], 0);
		dup(p[1], 1);
		close(p[0]);
		close(p[1]);
		exec("/boot/kfs", arg);
		fatal("can't exec kfs");
	default:
		break;
	}
	for(;;){
		if((i = waitpid()) == -1)
			fatal("waitpid for kfs failed");
		if(i == pid)
			break;
	}

	close(p[1]);
	return p[0];
}

void
runv(char **argv)
{
	int i, pid;

	switch(pid = fork()){
	case -1:
		fatal("fork");
	case 0:
		exec(argv[0], argv);
		fatal(smprint("can't exec %s: %r", argv[0]));
	default:
		while ((i = waitpid()) != pid && i != -1)
			;
		if(i == -1)
			fatal(smprint("wait failed running %s", argv[0]));
	}
}

void
run(char *file, ...)
{
	runv(&file);
}

static int
print1(int fd, char *s)
{
	return write(fd, s, strlen(s));
}

void
configloopback(void)
{
	int fd;

	if((fd = open("/net/ipifc/clone", ORDWR)) < 0){
		bind("#I", "/net", MAFTER);
		if((fd = open("/net/ipifc/clone", ORDWR)) < 0)
			fatal("open /net/ipifc/clone for loopback");
	}
	if(print1(fd, "bind loopback /dev/null") < 0
	|| print1(fd, "add 127.0.0.1 255.255.255.255") < 0)
		fatal("write /net/ipifc/clone for loopback");
}

int
connectlocalfossil(void)
{
	int fd;
	char *venti, *f[32], *p;
	int nf;
	char partition[128], buf[512];
	char *dev;

	if(stat("/boot/fossil", statbuf, sizeof statbuf) < 0)
		return -1;

	/* look for fossil partition */
	dev = disk ? disk : bootdisk;
	snprint(partition, sizeof partition, "%sfossil", dev);
	fd = open(partition, OREAD);
	if(fd < 0){
		strcpy(partition, dev);
		fd = open(partition, OREAD);
		if(fd < 0)
			return -1;
	}
	memset(buf, 0, sizeof buf);
	pread(fd, buf, 512, 127*1024);
	close(fd);
	if(memcmp(buf, "fossil config\n", 14) != 0){
		if(strstr(partition, "/fossil"))
			print("no fossil config found on %s\n", partition);
		return -1;
	}

	settime(1, -1, nil);

	/* make venti available.  give it 20% of free memory. */
	if((venti = getenv("venti")) && (nf = tokenize(venti, f, nelem(f)))){
		if((fd = open(f[0], OREAD)) >= 0){
			print("venti...");
			memset(buf, 0, sizeof buf);
			pread(fd, buf, 512, 248*1024);
			close(fd);
			if(memcmp(buf, "venti config\n", 13) != 0){
				print("no venti config found on %s\n", f[0]);
				return -1;
			}
			if(stat("/boot/venti", statbuf, sizeof statbuf) < 0){
				print("/boot/venti does not exist\n");
				return -1;
			}
			switch(nf){
			case 1:
				f[1] = "tcp!127.1!17034";
			case 2:
				f[2] = "tcp!127.1!8000";
			}
			configloopback();
			run("/boot/venti", "-m", "20", "-c", f[0],
				"-a", f[1], "-h", f[2], nil);
			/*
			 * If the announce address is tcp!*!foo, then set
			 * $venti to tcp!127.1!foo instead, which is actually dialable.
			 */
			if((p = strstr(f[1], "!*!")) != 0){
				*p = 0;
				snprint(buf, sizeof buf, "%s!127.1!%s", f[1], p+3);
				f[1] = buf;
			}
			setenv("venti", f[1]);
		}else{
			/* set up the network so we can talk to the venti server */
			/* this is such a crock. */
			configip(nf, f, 0);
			setenv("venti", f[0]);
		}
	}

	/* start fossil.  give it 20% of free memory. */
	print("fossil(%s)...", partition);
	run("/boot/fossil", "-m", "20", "-f", partition,
		"-c", "srv -A fboot", "-c", "srv -p fscons", nil);
	fd = open("#s/fboot", ORDWR);
	if(fd < 0){
		warning("open #s/fboot");
		return -1;
	}
	remove("#s/fboot");  /* we'll repost fd as #s/boot after fversion(fd) */
	return fd;
}

int
connectlocal(void)
{
	int fd;

	if(bind("#c", "/dev", MREPL) < 0)
		fatal("bind #c");
	if(bind("#p", "/proc", MREPL) < 0)
		fatal("bind #p");
	bind("#S", "/dev", MAFTER);
	bind("#k", "/dev", MAFTER);
	bind("#u", "/dev", MAFTER);
	bind("#æ", "/dev", MAFTER);
	mountusbparts();	/* make partfs partitions visible again */

	if((fd = connectlocalfossil()) < 0)
		fd = connectlocalkfs();
	return fd;
}
