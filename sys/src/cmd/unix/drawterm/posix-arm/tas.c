/* 
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

/* arm pre-v7 architecture */
#include "u.h"
#include "libc.h"

int
tas(long *x)
{
	int     v;

	__asm__(
		"swp  %0, %1, [%2]"
		: "=&r" (v)
		: "r" (1), "r" (x)
		: "memory"
	);
	switch(v) {
	case 0:
	case 1:
		return v;
	default:
		print("canlock: corrupted 0x%lux\n", v);
		return 1;
	}
}
