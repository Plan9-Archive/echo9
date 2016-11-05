#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>

int volume;
Image *knob;
Image *back;
Image *rim;

Point
volumept(Point c, int volume, int r) {
	double rad = (double) ((volume*3.0+30) * PI/180.0;

	c.x -= sin(rad) * r;
	c.y += cos(rad) * r;

	return c;
}

void
redraw(Image *screen)
{
	Point c = divpt(addpt(screen->r.min, screen->r.max), 2);
	Point winsize = subpt(screen->r.max, screen->r.min);
	int r = winsize.x > winsize.y? winsize.y/4: winsize.x/4;

	draw(screen, screen->r, back, nil, ZP);
	
	line(screen, volumept(c, 0, r+5), volumept(c, 0, r), 0, 0, 1, display->black, ZP);
	line(screen, volumept(c, 100, r+5), volumept(c, 100, r), 0, 0, 1, display->black, ZP);
	ellipse(screen, c, r, r, 1, rim, ZP);
	fillellipse(screen, volumept(c, volume, r-10), 3, 3, knob, ZP);

	flushimage(display, 1);
}

void
eresized(int new)
{
	if(new && getwindow(display, Refnone) < 0)
		fprint(2,"can't reattach to window");

	redraw(screen);
}

void
main()
{
	int key;
	Mouse m;
	Event e;
	int f;
	char buf[256];
	char *ptr;
	Point p;
	double rad;
	int d;
	int timer;

	f = open("/dev/volume", ORDWR);
	if (f < 0)
		sysfatal ("open volume failed");

	read (f, buf, sizeof(buf));
	strtok(buf, " ");
	ptr = strtok(nil, " ");
	volume = atoi(ptr);

	if (initdraw(0, 0, "volume") < 0)
		sysfatal ("initdraw failed");

	einit (Emouse);
	timer = etimer(0, 1000);

	back = allocimagemix (display, 0x88FF88FF, DWhite);
	knob = allocimage (display, Rect(0,0,1,1), CMAP8, 1, 0x008800FF);
	rim = allocimage (display, Rect(0,0,1,1), CMAP8, 1, 0x004400FF);

	redraw(screen);

	for (;;) {
		key = event(&e);

		if(key == Emouse) {
			m = e.mouse;
			if(m.buttons & 1) {
				p = subpt(m.xy, divpt(addpt(screen->r.min, screen->r.max), 2));
				rad = atan2(-p.x, p.y);
				d = rad * 180.0/PI;
				if (d < 0)
					d += 360;

				if (d < 30)
					volume = 0;
				else if (d > 330)
					volume = 100;
				else
					volume = ((d-30)/300.0)*100.0;

				fprint (f, "%d\n", volume);

				redraw(screen);

				sleep(50);
			}
		} else if(key == timer) {
			close(f);
			f = open("/dev/volume", ORDWR);
			if (f < 0)
				sysfatal ("open volume failed");

			read (f, buf, sizeof(buf));
			strtok(buf, " ");
			ptr = strtok(nil, " ");
			volume = atoi(ptr);

			redraw(screen);
		}
	}
}
