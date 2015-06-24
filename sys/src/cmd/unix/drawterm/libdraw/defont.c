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
#include <draw.h>

/*
 * lucm/latin1.9, in uncompressed form
 */
uchar
defontdata[] =
{
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x30,0x20,0x20,0x20,0x20,0x20,
0x20,0x20,0x20,0x20,0x20,0x20,0x30,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x20,0x20,0x30,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x32,0x33,0x30,0x34,0x20,
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x31,0x35,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x30,0x06,0x06,0x03,0x42,0x40,0x00,0x00,0x00,0x18,0x03,0x03,
0x02,0x43,0x00,0x60,0x60,0x48,0x00,0x0d,0x0c,0x01,0x81,0x80,0xd0,0x90,0x00,0x00,
0x18,0x01,0x81,0x81,0x40,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x7f,0x9c,0x1c,
0x0e,0x07,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x70,
0x38,0x1c,0x0e,0x04,0x81,0xc1,0xc0,0x70,0x00,0x1c,0x1c,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0x80,0xc0,0x63,0xe3,
0xf1,0xf8,0xfe,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x7f,0xff,0xff,0x1f,0x8f,
0xc7,0xe3,0xf1,0xfb,0x7e,0x3e,0x3f,0x8f,0xff,0xe3,0xe3,0xff,0xff,0xff,0xff,0xff,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0c,0x18,0x09,0x05,0x82,0x40,0xc0,0x00,0x00,0x06,0x0c,0x04,
0x82,0x40,0xc1,0x80,0x90,0x48,0x00,0x16,0x03,0x06,0x02,0x41,0x60,0x90,0x00,0x00,
0x06,0x06,0x02,0x41,0x41,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3e,0x7f,0xa0,0x10,
0x08,0x04,0x02,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x48,
0x24,0x12,0x09,0x06,0x82,0x01,0x00,0x90,0x00,0x20,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x04,0x80,0x00,0x40,0x00,0x00,0x38,0x06,0x18,0x00,0x00,0x00,0x00,0x00,
0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x07,0xc6,0x01,0xf0,0x00,0x00,0x0c,0x00,0x18,0x00,0x00,0x30,0x00,0x3c,
0x00,0x60,0x06,0x01,0x8c,0x07,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xe0,0xc3,0xc0,0x01,0x54,0x9c,0xc0,0x5f,0xef,
0xf7,0xfb,0xfd,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0x7f,0xff,0xff,0x6f,0xb7,
0xdb,0xed,0xf6,0xf9,0x7d,0xfe,0xff,0x6f,0xff,0xdf,0xef,0xff,0xff,0xff,0xff,0xff,
0xff,0x00,0x01,0x00,0x00,0x00,0x00,0x30,0x00,0x14,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x20,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x30,0x06,0x06,0x06,0x82,0x80,0xc0,0x00,
0x00,0x18,0x03,0x03,0x02,0x41,0x80,0x30,0x30,0x24,0x76,0x0d,0x0c,0x00,0xc0,0xc0,
0xd0,0x50,0x00,0x00,0x18,0x01,0x81,0x81,0x40,0x30,0x00,0x28,0x0f,0x7f,0xbc,0x1c,
0x0e,0x07,0x03,0xc0,0x10,0x70,0x24,0x10,0x09,0x07,0x03,0x80,0xe0,0x70,0x90,0x48,
0x24,0x12,0x09,0x05,0x81,0x81,0xc0,0x80,0x70,0x18,0x1c,0x07,0x01,0xc1,0xc0,0x90,
0x00,0x0c,0x04,0x84,0x83,0xe1,0xc0,0xe0,0x38,0x0c,0x0c,0x02,0x00,0x00,0x00,0x00,
0x00,0x06,0x1c,0x06,0x0f,0x87,0xc0,0x63,0xf8,0x78,0xfe,0x3e,0x0e,0x00,0x00,0x00,
0x00,0x00,0x00,0x7c,0x1c,0x0c,0x1f,0x03,0xc7,0xc3,0xf1,0xf8,0x3c,0x63,0x3f,0x0f,
0x8c,0x66,0x06,0x19,0x84,0x78,0x7e,0x1e,0x1f,0x07,0xcf,0xf3,0x1b,0x0d,0x86,0x63,
0x61,0x9f,0xc6,0x06,0x00,0x30,0x00,0x00,0x10,0x00,0x18,0x00,0x00,0x30,0x00,0x60,
0x00,0x60,0x06,0x01,0x8c,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0xc0,0x60,0x00,0xaa,0xb6,0xc0,0x43,0xe3,
0xf1,0xf8,0xfc,0x3f,0xef,0x8f,0xdb,0xef,0xf6,0xf8,0xfb,0xff,0x1f,0x8f,0x6f,0xb7,
0xdb,0xed,0xf6,0xfa,0x7e,0x7e,0x3f,0x7f,0x8f,0xe7,0xe3,0xf8,0xfe,0x3e,0x3f,0x6f,
0x00,0x00,0x01,0x01,0xc8,0x0b,0x0c,0x30,0x7c,0x14,0x0f,0x0f,0x00,0x00,0x00,0x00,
0x78,0x00,0x1c,0x00,0x0f,0x07,0x81,0x80,0x00,0x7c,0x00,0x00,0x1c,0x0f,0x80,0x04,
0x42,0x23,0x90,0x00,0x18,0x0c,0x06,0x03,0x01,0x80,0xc0,0x3c,0x3c,0x3f,0x1f,0x8f,
0xc7,0xe7,0xe3,0xf1,0xf8,0xfc,0x7c,0x30,0x8f,0x07,0x83,0xc1,0xe0,0xf0,0x00,0x3d,
0x31,0x98,0xcc,0x66,0x36,0x19,0x80,0xcc,0x0c,0x18,0x09,0x0b,0x02,0x81,0x20,0x00,
0x00,0x06,0x0c,0x04,0x82,0x40,0x60,0xc0,0x48,0x24,0x18,0x16,0x03,0x03,0x01,0x21,
0x60,0x50,0x00,0x00,0x06,0x06,0x02,0x41,0x40,0xc1,0x80,0x28,0x87,0x7f,0x84,0x10,
0x08,0x04,0x02,0x40,0x38,0x48,0x24,0x10,0x09,0x04,0x04,0x81,0x00,0x80,0x90,0x48,
0x24,0x12,0x09,0x04,0x80,0x41,0x00,0x80,0x40,0x04,0x10,0x04,0x02,0x01,0x20,0x90,
0x00,0x0c,0x04,0x84,0x86,0x53,0x65,0xb0,0x08,0x18,0x06,0x0a,0x80,0x00,0x00,0x00,
0x00,0x0c,0x36,0x0e,0x19,0xcc,0xe0,0xe3,0xf8,0xcc,0xfe,0x63,0x1b,0x00,0x00,0x00,
0x00,0x00,0x00,0xc6,0x62,0x0c,0x19,0x86,0x66,0x63,0x01,0x80,0x66,0x63,0x0c,0x01,
0x8c,0xc6,0x06,0x19,0xc4,0xcc,0x63,0x33,0x19,0x8c,0x61,0x83,0x1b,0x0d,0x86,0x63,
0x61,0x80,0xc6,0x03,0x00,0x30,0x30,0x00,0x1c,0x00,0x18,0x00,0x00,0x30,0x00,0x60,
0x00,0x60,0x00,0x00,0x0c,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0xc0,0x60,0x01,0x54,0x86,0xc0,0x7b,0xef,
0xf7,0xfb,0xfd,0xbf,0xc7,0xb7,0xdb,0xef,0xf6,0xfb,0xfb,0x7e,0xff,0x7f,0x6f,0xb7,
0xdb,0xed,0xf6,0xfb,0x7f,0xbe,0xff,0x7f,0xbf,0xfb,0xef,0xfb,0xfd,0xfe,0xdf,0x6f,
0xff,0x00,0x07,0x83,0x24,0x13,0x0c,0x30,0xc6,0x00,0x10,0x81,0x80,0x00,0x00,0x00,
0x84,0x00,0x22,0x00,0x01,0x80,0xc0,0x00,0x00,0xf4,0x00,0x00,0x2c,0x18,0xc0,0x0c,
0x46,0x20,0x90,0x00,0x18,0x0c,0x06,0x03,0x01,0x80,0xc0,0x70,0x66,0x30,0x18,0x0c,
0x06,0x01,0x80,0xc0,0x60,0x30,0x66,0x38,0x99,0x8c,0xc6,0x63,0x31,0x98,0x00,0x66,
0x31,0x98,0xcc,0x66,0x36,0x19,0x80,0xcc,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6c,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0xff,0x7f,0xb8,0x1c,
0x0e,0x07,0x02,0x40,0x7c,0x70,0x3c,0x10,0x09,0x07,0x04,0x00,0xc0,0x60,0xe0,0x70,
0x38,0x1c,0x0e,0x04,0x83,0x81,0xc0,0x70,0x70,0x38,0x1c,0x07,0x02,0xc1,0xc0,0x90,
0x00,0x0c,0x00,0x04,0x86,0x43,0x69,0xb0,0x30,0x18,0x06,0x07,0x01,0x00,0x00,0x00,
0x00,0x0c,0x63,0x16,0x00,0xc0,0x61,0x62,0x01,0x80,0x06,0x63,0x31,0x80,0x00,0x00,
0x60,0x00,0xc0,0x06,0x43,0x16,0x19,0x8c,0x06,0x33,0x01,0x80,0xc0,0x63,0x0c,0x01,
0x8c,0x86,0x07,0x39,0xc5,0x86,0x63,0x61,0x99,0x8c,0x01,0x83,0x1b,0x0d,0xb6,0x63,
0x31,0x01,0x86,0x03,0x00,0x30,0x30,0x00,0x1c,0x3e,0x1b,0x03,0xc1,0xf0,0xf0,0x60,
0x3e,0x6e,0x3e,0x0f,0x8c,0x60,0xc5,0xb1,0xb8,0x38,0x6c,0x0f,0x8c,0xc7,0xc1,0x83,
0x19,0x8d,0x82,0x63,0x31,0x9f,0xc1,0x80,0xc0,0xc0,0x00,0xaa,0x86,0xc0,0x47,0xe3,
0xf1,0xf8,0xfd,0xbf,0x83,0x8f,0xc3,0xef,0xf6,0xf8,0xfc,0xff,0x3f,0x9f,0x1f,0x8f,
0xc7,0xe3,0xf1,0xfb,0x7c,0x7e,0x3f,0x8f,0x8f,0xc7,0xe3,0xf8,0xfd,0x3e,0x3f,0x6f,
0x00,0x0c,0x0d,0x43,0x03,0xe1,0x88,0x30,0xc0,0x00,0x27,0x41,0x80,0x00,0x00,0x01,
0x72,0x00,0x22,0x04,0x01,0x80,0xc0,0x03,0x18,0xf4,0x00,0x00,0x0c,0x18,0xc0,0x04,
0x82,0x43,0x20,0x18,0x2c,0x16,0x0b,0x05,0x82,0xc1,0x60,0xb0,0xc0,0x30,0x18,0x0c,
0x06,0x01,0x80,0xc0,0x60,0x30,0x63,0x38,0xb0,0xd8,0x6c,0x36,0x1b,0x0c,0x00,0xc7,
0x31,0x98,0xcc,0x66,0x33,0x11,0xf8,0xc8,0x7c,0x3e,0x1f,0x0f,0x87,0xc3,0xe1,0xd8,
0x3c,0x1e,0x0f,0x07,0x83,0xc7,0xc3,0xe1,0xf0,0xf8,0x06,0x37,0x07,0x03,0x81,0xc0,
0xe0,0x70,0x10,0x1d,0x31,0x98,0xcc,0x66,0x33,0x19,0xb0,0xc6,0x8f,0x7f,0x87,0x03,
0x81,0x80,0x90,0x30,0x6c,0x48,0x24,0x10,0x06,0x04,0x04,0x80,0x20,0x10,0x10,0x0e,
0x07,0x03,0x81,0xc0,0x60,0x88,0x38,0x0c,0x40,0x09,0x03,0x84,0x02,0x41,0x40,0x90,
0x00,0x0c,0x00,0x1f,0xe7,0x41,0xd1,0xa0,0x00,0x30,0x03,0x0a,0x81,0x00,0x00,0x00,
0x00,0x18,0x63,0x06,0x00,0xc0,0xc2,0x62,0x01,0xb0,0x0c,0x72,0x31,0x86,0x03,0x00,
0xc0,0x00,0x60,0x06,0x8f,0x16,0x19,0x0c,0x06,0x33,0x01,0x80,0xc0,0x63,0x0c,0x01,
0x8d,0x06,0x07,0x39,0x65,0x86,0x63,0x61,0x99,0x0e,0x01,0x83,0x19,0x89,0xb6,0x32,
0x33,0x03,0x06,0x01,0x80,0x30,0x78,0x00,0x00,0x03,0x1d,0x86,0x23,0x31,0x99,0xfc,
0x66,0x77,0x06,0x01,0x8c,0x40,0xc6,0xd9,0xdc,0x6c,0x76,0x19,0x8d,0xcc,0x27,0xf3,
0x19,0x8d,0x82,0x63,0x31,0x80,0xc0,0x80,0xc0,0x80,0x01,0x54,0x8c,0xc0,0x78,0xfc,
0x7e,0x7f,0x6f,0xcf,0x93,0xb7,0xdb,0xef,0xf9,0xfb,0xff,0xff,0xdf,0xef,0xef,0xf1,
0xf8,0xfc,0x7e,0x3f,0x9f,0x77,0xc7,0xf3,0xbf,0xf6,0xfc,0x7b,0xfd,0xbe,0xbf,0x6f,
0xff,0x0c,0x19,0x03,0x03,0x61,0x98,0x30,0x78,0x00,0x28,0x4f,0x83,0x30,0x00,0x01,
0x4a,0x00,0x1c,0x04,0x03,0x03,0x80,0x03,0x18,0xf4,0x00,0x00,0x0c,0x18,0xd9,0x84,
0x82,0x40,0xa0,0x18,0x2c,0x16,0x0b,0x05,0x82,0xc1,0x60,0xb0,0xc0,0x30,0x18,0x0c,
0x06,0x01,0x80,0xc0,0x60,0x30,0x63,0x2c,0xb0,0xd8,0x6c,0x36,0x1b,0x0c,0x64,0xcb,
0x31,0x98,0xcc,0x66,0x33,0x31,0x8c,0xd8,0x06,0x03,0x01,0x80,0xc0,0x60,0x30,0x6c,
0x62,0x33,0x19,0x8c,0xc6,0x60,0xc0,0x60,0x30,0x18,0x1e,0x3b,0x8d,0x86,0xc3,0x61,
0xb0,0xd8,0x10,0x36,0x31,0x98,0xcc,0x66,0x33,0x19,0xd8,0xc6,0x0f,0x7f,0x82,0x01,
0x02,0x40,0xd0,0x40,0x6c,0x70,0x24,0x1c,0x06,0x04,0x03,0x01,0xc0,0xe0,0x10,0x12,
0x09,0x04,0x82,0x40,0x90,0x50,0x10,0x12,0x70,0x09,0x04,0x04,0x01,0xc1,0x20,0x60,
0x00,0x0c,0x00,0x04,0x83,0xc0,0x20,0xcc,0x00,0x30,0x03,0x02,0x01,0x00,0x00,0x00,
0x00,0x18,0x63,0x06,0x01,0x83,0x84,0x63,0xf1,0xd8,0x18,0x3c,0x31,0x86,0x03,0x01,
0x83,0xf8,0x30,0x1c,0x9b,0x33,0x1e,0x0c,0x06,0x33,0xe1,0x80,0xc0,0x7f,0x0c,0x01,
0x8f,0x06,0x07,0x79,0x65,0x86,0x66,0x61,0x9e,0x07,0x81,0x83,0x19,0x89,0xb6,0x1c,
0x1a,0x03,0x06,0x01,0x80,0x30,0x48,0x00,0x00,0x03,0x18,0xcc,0x06,0x33,0x18,0x60,
0xc6,0x63,0x06,0x01,0x8c,0x80,0xc6,0xd9,0x8c,0xc6,0x63,0x31,0x8e,0x4c,0x01,0x83,
0x19,0x8d,0x92,0x32,0x31,0x81,0x87,0x00,0xc0,0x70,0xe4,0xaa,0x98,0xc0,0x7d,0xfe,
0xfd,0xbf,0x2f,0xbf,0x93,0x8f,0xdb,0xe3,0xf9,0xfb,0xff,0x1e,0x3f,0x1f,0xef,0xed,
0xf6,0xfb,0x7d,0xbf,0x6f,0xaf,0xef,0xed,0x8f,0xf6,0xfb,0xfb,0xfe,0x3e,0xdf,0x9f,
0x00,0x00,0x19,0x0f,0xc6,0x30,0xd0,0x00,0xcc,0x00,0x28,0x59,0x86,0x67,0xf0,0x01,
0x72,0x00,0x00,0x3f,0x86,0x00,0xc0,0x03,0x18,0xf4,0x00,0x00,0x0c,0x18,0xcc,0xc5,
0x32,0x83,0x4c,0x00,0x66,0x33,0x19,0x8c,0xc6,0x63,0x31,0xbc,0xc0,0x3e,0x1f,0x0f,
0x87,0xc1,0x80,0xc0,0x60,0x30,0xfb,0x2c,0xb0,0xd8,0x6c,0x36,0x1b,0x0c,0x38,0xcb,
0x31,0x98,0xcc,0x66,0x31,0xa1,0x8c,0xcc,0x06,0x03,0x01,0x80,0xc0,0x60,0x30,0x6c,
0xc0,0x63,0x31,0x98,0xcc,0x60,0xc0,0x60,0x30,0x18,0x37,0x31,0x98,0xcc,0x66,0x33,
0x19,0x8c,0x00,0x67,0x31,0x98,0xcc,0x66,0x33,0x19,0x8c,0xc6,0x1f,0x7f,0x82,0x01,
0x02,0x40,0xb0,0x40,0x6c,0x07,0x03,0x83,0x80,0xe0,0xe0,0x00,0x18,0x0e,0x10,0x10,
0x08,0x04,0x02,0x00,0xf0,0x20,0x10,0x1e,0x08,0x89,0x03,0x00,0xe0,0x38,0x1c,0x0e,
0x00,0x0c,0x00,0x04,0x81,0xe0,0x41,0x6c,0x00,0x30,0x03,0x00,0x0f,0xe0,0x03,0xf8,
0x00,0x30,0x63,0x06,0x03,0x00,0xc7,0xf0,0x39,0x8c,0x30,0x3e,0x1b,0x80,0x00,0x03,
0x00,0x00,0x18,0x30,0x9b,0x23,0x19,0x0c,0x06,0x33,0x01,0xf8,0xc6,0x63,0x0c,0x01,
0x8d,0x86,0x05,0xd9,0x35,0x86,0x7c,0x61,0x9b,0x01,0xc1,0x83,0x19,0x99,0xb4,0x1c,
0x0c,0x06,0x06,0x00,0xc0,0x30,0xcc,0x00,0x00,0x3f,0x18,0xcc,0x06,0x33,0xf8,0x60,
0xc6,0x63,0x06,0x01,0x8f,0x00,0xc6,0xd9,0x8c,0xc6,0x63,0x31,0x8c,0x0f,0x81,0x83,
0x18,0xd9,0xba,0x1c,0x1b,0x03,0x00,0x80,0xc0,0x81,0x75,0x54,0x98,0xc0,0x7d,0xfe,
0xfd,0xbf,0x4f,0xbf,0x93,0xf8,0xfc,0x7c,0x7f,0x1f,0x1f,0x6f,0xe7,0xf1,0xef,0xef,
0xf7,0xfb,0xfd,0xff,0x0f,0xdf,0xef,0xe1,0xf7,0x76,0xfc,0xff,0x1f,0xc7,0xe3,0xf1,
0xff,0x08,0x19,0x03,0x06,0x31,0xf8,0x00,0xc6,0x00,0x28,0x5b,0x8c,0xc0,0x11,0xf1,
0x4a,0x00,0x00,0x04,0x0c,0x00,0xc0,0x03,0x18,0x74,0x38,0x00,0x0c,0x18,0xc6,0x65,
0x52,0xb8,0x54,0x18,0x46,0x23,0x11,0x88,0xc4,0x62,0x31,0x30,0xc0,0x30,0x18,0x0c,
0x06,0x01,0x80,0xc0,0x60,0x30,0x63,0x26,0xb0,0xd8,0x6c,0x36,0x1b,0x0c,0x10,0xd3,
0x31,0x98,0xcc,0x66,0x30,0xc1,0x8c,0xc6,0x7e,0x3f,0x1f,0x8f,0xc7,0xe3,0xf1,0xfc,
0xc0,0x7f,0x3f,0x9f,0xcf,0xe0,0xc0,0x60,0x30,0x18,0x63,0x31,0x98,0xcc,0x66,0x33,
0x19,0x8c,0xfe,0x6b,0x31,0x98,0xcc,0x66,0x31,0xb1,0x8c,0x6c,0x0e,0x7f,0x82,0x01,
0x01,0x80,0x90,0x30,0xc6,0x08,0x01,0x02,0x00,0x40,0x80,0xe0,0x24,0x04,0x1c,0x10,
0x08,0x04,0x02,0x00,0x90,0x20,0x10,0x12,0x0d,0x86,0x00,0x81,0x00,0x40,0x20,0x10,
0x00,0x04,0x00,0x1f,0xe1,0x70,0xbb,0x28,0x00,0x30,0x03,0x00,0x01,0x00,0x00,0x00,
0x00,0x30,0x63,0x06,0x06,0x00,0x67,0xf0,0x19,0x8c,0x30,0x67,0x0d,0x80,0x00,0x01,
0x83,0xf8,0x30,0x30,0x9b,0x7f,0x19,0x8c,0x06,0x33,0x01,0x80,0xc6,0x63,0x0c,0x01,
0x8c,0xc6,0x05,0xd9,0x35,0x86,0x60,0x61,0x99,0x80,0xe1,0x83,0x18,0xd0,0xdc,0x26,
0x0c,0x0c,0x06,0x00,0xc0,0x30,0x84,0x00,0x00,0x63,0x18,0xcc,0x06,0x33,0x00,0x60,
0xc6,0x63,0x06,0x01,0x8d,0x80,0xc6,0xd9,0x8c,0xc6,0x63,0x31,0x8c,0x03,0xe1,0x83,
0x18,0xd9,0xba,0x1c,0x1b,0x06,0x01,0x80,0xc0,0xc1,0x38,0xaa,0x80,0xc0,0x7d,0xfe,
0xfe,0x7f,0x6f,0xcf,0x39,0xf7,0xfe,0xfd,0xff,0xbf,0x7f,0x0f,0xdb,0xfb,0xe3,0xef,
0xf7,0xfb,0xfd,0xff,0x6f,0xdf,0xef,0xed,0xf2,0x79,0xff,0x7e,0xff,0xbf,0xdf,0xef,
0x00,0x0c,0x19,0x03,0x03,0x60,0x60,0x30,0x66,0x00,0x28,0x4d,0xc6,0x60,0x10,0x00,
0x84,0x00,0x00,0x04,0x0f,0x87,0x80,0x03,0x18,0x14,0x38,0x00,0x3f,0x0f,0x8c,0xc2,
0x90,0x84,0xa4,0x18,0xfe,0x7f,0x3f,0x9f,0xcf,0xe7,0xf1,0xf0,0xc0,0x30,0x18,0x0c,
0x06,0x01,0x80,0xc0,0x60,0x30,0x63,0x26,0xb0,0xd8,0x6c,0x36,0x1b,0x0c,0x38,0xd3,
0x31,0x98,0xcc,0x66,0x30,0xc1,0x98,0xc6,0xc6,0x63,0x31,0x98,0xcc,0x66,0x33,0x60,
0xc0,0x60,0x30,0x18,0x0c,0x00,0xc0,0x60,0x30,0x18,0x63,0x31,0x98,0xcc,0x66,0x33,
0x19,0x8c,0x00,0x6b,0x31,0x98,0xcc,0x66,0x31,0xb1,0x8c,0x6c,0x1c,0x7f,0x81,0x20,
0x90,0x38,0x18,0x0b,0x83,0x06,0x01,0x03,0x80,0x40,0xe0,0x90,0x24,0x04,0x03,0x8e,
0x86,0xc3,0x61,0x90,0x24,0x12,0x0e,0x04,0x8a,0x81,0xc7,0x70,0xc0,0x30,0x18,0x0c,
0x00,0x00,0x00,0x04,0x81,0x31,0x6f,0x30,0x00,0x18,0x06,0x00,0x01,0x00,0x00,0x00,
0x00,0x60,0x63,0x06,0x0c,0x00,0x60,0x60,0x19,0x8c,0x60,0x63,0x01,0x80,0x00,0x00,
0xc0,0x00,0x60,0x00,0x4d,0xe1,0x99,0x8c,0x06,0x33,0x01,0x80,0xc6,0x63,0x0c,0x01,
0x8c,0xc6,0x04,0x99,0x1d,0x86,0x60,0x61,0x99,0x80,0x61,0x83,0x18,0xd0,0xdc,0x63,
0x0c,0x0c,0x06,0x00,0x60,0x30,0x84,0x00,0x00,0x63,0x18,0xcc,0x06,0x33,0x00,0x60,
0x6e,0x63,0x06,0x01,0x8c,0xc0,0xc6,0xd9,0x8c,0xc6,0x63,0x31,0x8c,0x00,0x61,0x83,
0x18,0xd0,0xcc,0x26,0x0e,0x0c,0x03,0x00,0xc0,0x60,0x01,0x54,0x98,0xc0,0x7e,0xdf,
0x6f,0xc7,0xe7,0xf4,0x7c,0xf9,0xfe,0xfc,0x7f,0xbf,0x1f,0x5f,0xdb,0xfb,0xfc,0x71,
0x79,0x3c,0x9e,0x6f,0xdb,0xed,0xf1,0xfb,0x75,0x7e,0x38,0x8f,0x3f,0xcf,0xe7,0xf3,
0xff,0x0c,0x0d,0x03,0x03,0xe1,0xf8,0x30,0x3c,0x00,0x27,0x40,0x03,0x30,0x00,0x00,
0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x18,0x14,0x00,0x00,0x00,0x00,0x19,0x82,
0xf8,0x98,0xbe,0x70,0xc3,0x61,0xb0,0xd8,0x6c,0x36,0x1b,0x30,0xc0,0x30,0x18,0x0c,
0x06,0x01,0x80,0xc0,0x60,0x30,0x63,0x23,0xb0,0xd8,0x6c,0x36,0x1b,0x0c,0x4c,0xe3,
0x31,0x98,0xcc,0x66,0x30,0xc1,0xf0,0xc6,0xc6,0x63,0x31,0x98,0xcc,0x66,0x33,0x60,
0xc0,0x60,0x30,0x18,0x0c,0x00,0xc0,0x60,0x30,0x18,0x63,0x31,0x98,0xcc,0x66,0x33,
0x19,0x8c,0x10,0x73,0x31,0x98,0xcc,0x66,0x30,0xe1,0x8c,0x38,0x1c,0x7f,0x80,0xa0,
0x50,0x10,0x24,0x0d,0xff,0x01,0x01,0x02,0x00,0x40,0x80,0xf0,0x24,0x04,0x02,0x01,
0x81,0x20,0x10,0x30,0x28,0x1a,0x09,0x06,0x8a,0x81,0x20,0x90,0x20,0x08,0x04,0x02,
0x00,0x0c,0x00,0x04,0x85,0x32,0x6f,0xb8,0x00,0x18,0x06,0x00,0x01,0x01,0xc0,0x00,
0x70,0x60,0x36,0x06,0x1f,0xcc,0xe0,0x63,0x30,0xd8,0x60,0x63,0x33,0x06,0x03,0x00,
0x60,0x00,0xc0,0x30,0x60,0x61,0x99,0x86,0x66,0x63,0x01,0x80,0x66,0x63,0x0c,0x03,
0x0c,0x66,0x04,0x19,0x1c,0xcc,0x60,0x33,0x18,0xcc,0x61,0x81,0xb0,0x60,0xcc,0x63,
0x0c,0x18,0x06,0x00,0x60,0x30,0x00,0x00,0x00,0x67,0x19,0x86,0x23,0x71,0x88,0x60,
0x36,0x63,0x06,0x01,0x8c,0x60,0xc6,0xd9,0x8c,0x6c,0x66,0x1b,0x8c,0x08,0x61,0x83,
0xb8,0x70,0xcc,0x63,0x0c,0x18,0x03,0x00,0xc0,0x60,0x00,0xaa,0x98,0xc0,0x7f,0x5f,
0xaf,0xef,0xdb,0xf2,0x00,0xfe,0xfe,0xfd,0xff,0xbf,0x7f,0x6f,0xdb,0xfb,0xfd,0xfe,
0x7e,0xdf,0xef,0xcf,0xd7,0xe5,0xf6,0xf9,0x75,0x7e,0xdf,0x6f,0xdf,0xf7,0xfb,0xfd,
0x00,0x0c,0x07,0xc6,0x04,0x10,0x60,0x30,0x06,0x00,0x10,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x3f,0x80,0x00,0x00,0x03,0xb8,0x14,0x00,0x00,0x00,0x00,0x00,0x04,
0x11,0x21,0x04,0xc0,0xc3,0x61,0xb0,0xd8,0x6c,0x36,0x1b,0x30,0x66,0x30,0x18,0x0c,
0x06,0x01,0x80,0xc0,0x60,0x30,0x66,0x23,0x99,0x8c,0xc6,0x63,0x31,0x98,0x00,0x66,
0x1b,0x0d,0x86,0xc3,0x60,0xc1,0x80,0xc6,0xce,0x67,0x33,0x99,0xcc,0xe6,0x73,0x74,
0x62,0x31,0x18,0x8c,0x46,0x20,0xc0,0x60,0x30,0x18,0x36,0x31,0x8d,0x86,0xc3,0x61,
0xb0,0xd8,0x10,0x36,0x3b,0x9d,0xce,0xe7,0x70,0xc1,0x98,0x30,0x00,0x7f,0x80,0xc0,
0x60,0x10,0x24,0x0c,0x38,0x0e,0x01,0x02,0x00,0x40,0x80,0xa0,0x18,0x0e,0x03,0x00,
0x80,0x40,0x60,0x50,0x30,0x16,0x0e,0x05,0x88,0x81,0xc0,0x81,0xc0,0x70,0x38,0x1c,
0x00,0x0c,0x00,0x04,0x83,0xe0,0x39,0xcc,0x00,0x0c,0x0c,0x00,0x00,0x01,0xc0,0x00,
0x70,0xc0,0x1c,0x06,0x1f,0xc7,0xc0,0x61,0xe0,0x70,0x60,0x3e,0x1e,0x06,0x03,0x00,
0x00,0x00,0x00,0x30,0x1e,0x61,0x9f,0x03,0xc7,0xc3,0xf1,0x80,0x3e,0x63,0x3f,0x1e,
0x0c,0x67,0xe4,0x19,0x0c,0x78,0x60,0x1e,0x18,0xc7,0xc1,0x80,0xe0,0x60,0xcc,0x63,
0x0c,0x1f,0xc6,0x00,0x30,0x30,0x00,0x00,0x00,0x3b,0x9f,0x03,0xc1,0xb0,0xf0,0x60,
0x06,0x63,0x06,0x01,0x8c,0x70,0xc6,0xd9,0x8c,0x38,0x7c,0x0d,0x8c,0x07,0xc0,0xf1,
0xd8,0x60,0xcc,0x63,0x0c,0x1f,0xc3,0x00,0xc0,0x60,0x01,0x54,0x80,0xc0,0x7f,0x3f,
0x9f,0xef,0xdb,0xf3,0xc7,0xf1,0xfe,0xfd,0xff,0xbf,0x7f,0xff,0xe7,0xf1,0xfc,0xff,
0x7f,0xbf,0x9f,0xaf,0xcf,0xe9,0xf1,0xfa,0x77,0x7e,0x3f,0x7e,0x3f,0x8f,0xc7,0xe3,
0xff,0x0c,0x01,0x0f,0xe8,0x08,0x60,0x30,0xc6,0x00,0x0f,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xd8,0x14,0x00,0x00,0x00,0x00,0x00,0x04,
0x11,0x3d,0x04,0xc0,0xc3,0x61,0xb0,0xd8,0x6c,0x36,0x1b,0x3c,0x3c,0x3f,0x1f,0x8f,
0xc7,0xe7,0xe3,0xf1,0xf8,0xfc,0x7c,0x21,0x8f,0x07,0x83,0xc1,0xe0,0xf0,0x00,0xbc,
0x0e,0x07,0x03,0x81,0xc0,0xc1,0x80,0xcc,0x77,0x3b,0x9d,0xce,0xe7,0x73,0xb9,0x98,
0x3c,0x1e,0x0f,0x07,0x83,0xc0,0xc0,0x60,0x30,0x18,0x1c,0x31,0x87,0x03,0x81,0xc0,
0xe0,0x70,0x00,0x5c,0x1d,0x8e,0xc7,0x63,0xb0,0xc1,0xf0,0x30,0x00,0x7f,0x81,0x40,
0xa0,0x10,0x28,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x00,0x00,0x02,0x00,
0x80,0x80,0x10,0xf8,0x28,0x12,0x09,0x04,0x80,0x01,0x20,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x06,0x18,0x00,0x00,0x00,0x40,0x00,
0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x07,0xc0,0x31,0xf0,0x01,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xcc,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x60,0x01,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x18,0x00,0x01,0xe0,0xc3,0xc0,0x00,0x00,0xff,0xc0,0x7e,0xbf,
0x5f,0xef,0xd7,0xf5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xff,
0x7f,0x7f,0xef,0x07,0xd7,0xed,0xf6,0xfb,0x7f,0xfe,0xdf,0x7f,0xff,0xff,0xff,0xff,
0x00,0x0c,0x01,0x00,0x00,0x00,0x00,0x30,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x14,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xc6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x81,0x80,0x60,0x00,0x7f,0x81,0x20,
0x90,0x10,0x1c,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,
0x81,0xe0,0x60,0x10,0x24,0x12,0x0e,0x04,0x80,0x01,0xc0,0x70,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x78,0x00,0x00,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x01,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xfe,0xdf,
0x6f,0xef,0xe3,0xf5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x7f,
0x7e,0x1f,0x9f,0xef,0xdb,0xed,0xf1,0xfb,0x7f,0xfe,0x3f,0x8f,0xff,0xff,0xff,0xff,
0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x81,0x80,0x60,0x20,0x20,0x20,0x20,
0x20,0x20,0x20,0x20,0x32,0x35,0x36,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x20,0x31,0x35,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x31,0x33,0x20,
0x00,0x00,0x01,0x0c,0x00,0x09,0x09,0x00,0x01,0x0f,0x00,0x09,0x12,0x00,0x01,0x0f,
0x00,0x09,0x1b,0x00,0x01,0x0f,0x00,0x09,0x24,0x00,0x01,0x0f,0x00,0x09,0x2d,0x00,
0x01,0x0f,0x00,0x09,0x36,0x00,0x01,0x0f,0x00,0x09,0x3f,0x00,0x03,0x0d,0x00,0x09,
0x48,0x00,0x03,0x0d,0x00,0x09,0x51,0x00,0x03,0x0d,0x00,0x09,0x5a,0x00,0x03,0x0d,
0x00,0x09,0x63,0x00,0x03,0x0d,0x00,0x09,0x6c,0x00,0x03,0x0d,0x00,0x09,0x75,0x00,
0x03,0x0e,0x00,0x09,0x7e,0x00,0x03,0x0d,0x00,0x09,0x87,0x00,0x03,0x0d,0x00,0x09,
0x90,0x00,0x01,0x0f,0x00,0x09,0x99,0x00,0x01,0x0f,0x00,0x09,0xa2,0x00,0x01,0x0f,
0x00,0x09,0xab,0x00,0x01,0x0f,0x00,0x09,0xb4,0x00,0x01,0x0f,0x00,0x09,0xbd,0x00,
0x01,0x0f,0x00,0x09,0xc6,0x00,0x01,0x0f,0x00,0x09,0xcf,0x00,0x01,0x0f,0x00,0x09,
0xd8,0x00,0x01,0x0f,0x00,0x09,0xe1,0x00,0x03,0x0d,0x00,0x09,0xea,0x00,0x01,0x0f,
0x00,0x09,0xf3,0x00,0x01,0x0f,0x00,0x09,0xfc,0x00,0x03,0x0d,0x00,0x09,0x05,0x01,
0x03,0x0d,0x00,0x09,0x0e,0x01,0x03,0x0d,0x00,0x09,0x17,0x01,0x03,0x0d,0x00,0x09,
0x20,0x01,0x00,0x00,0x00,0x09,0x29,0x01,0x03,0x0d,0x00,0x09,0x32,0x01,0x02,0x05,
0x00,0x09,0x3b,0x01,0x03,0x0d,0x00,0x09,0x44,0x01,0x02,0x0e,0x00,0x09,0x4d,0x01,
0x03,0x0d,0x00,0x09,0x56,0x01,0x03,0x0d,0x00,0x09,0x5f,0x01,0x02,0x06,0x00,0x09,
0x68,0x01,0x02,0x0e,0x00,0x09,0x71,0x01,0x02,0x0e,0x00,0x09,0x7a,0x01,0x03,0x08,
0x00,0x09,0x83,0x01,0x05,0x0c,0x00,0x09,0x8c,0x01,0x0b,0x0f,0x00,0x09,0x95,0x01,
0x08,0x09,0x00,0x09,0x9e,0x01,0x0b,0x0d,0x00,0x09,0xa7,0x01,0x02,0x0e,0x00,0x09,
0xb0,0x01,0x03,0x0d,0x00,0x09,0xb9,0x01,0x03,0x0d,0x00,0x09,0xc2,0x01,0x03,0x0d,
0x00,0x09,0xcb,0x01,0x03,0x0d,0x00,0x09,0xd4,0x01,0x03,0x0d,0x00,0x09,0xdd,0x01,
0x03,0x0d,0x00,0x09,0xe6,0x01,0x03,0x0d,0x00,0x09,0xef,0x01,0x03,0x0d,0x00,0x09,
0xf8,0x01,0x03,0x0d,0x00,0x09,0x01,0x02,0x03,0x0d,0x00,0x09,0x0a,0x02,0x06,0x0d,
0x00,0x09,0x13,0x02,0x06,0x0f,0x00,0x09,0x1c,0x02,0x05,0x0c,0x00,0x09,0x25,0x02,
0x07,0x0a,0x00,0x09,0x2e,0x02,0x05,0x0c,0x00,0x09,0x37,0x02,0x03,0x0d,0x00,0x09,
0x40,0x02,0x03,0x0d,0x00,0x09,0x49,0x02,0x03,0x0d,0x00,0x09,0x52,0x02,0x03,0x0d,
0x00,0x09,0x5b,0x02,0x03,0x0d,0x00,0x09,0x64,0x02,0x03,0x0d,0x00,0x09,0x6d,0x02,
0x03,0x0d,0x00,0x09,0x76,0x02,0x03,0x0d,0x00,0x09,0x7f,0x02,0x03,0x0d,0x00,0x09,
0x88,0x02,0x03,0x0d,0x00,0x09,0x91,0x02,0x03,0x0d,0x00,0x09,0x9a,0x02,0x03,0x0d,
0x00,0x09,0xa3,0x02,0x03,0x0d,0x00,0x09,0xac,0x02,0x03,0x0d,0x00,0x09,0xb5,0x02,
0x03,0x0d,0x00,0x09,0xbe,0x02,0x03,0x0d,0x00,0x09,0xc7,0x02,0x03,0x0d,0x00,0x09,
0xd0,0x02,0x03,0x0d,0x00,0x09,0xd9,0x02,0x03,0x0f,0x00,0x09,0xe2,0x02,0x03,0x0d,
0x00,0x09,0xeb,0x02,0x03,0x0d,0x00,0x09,0xf4,0x02,0x03,0x0d,0x00,0x09,0xfd,0x02,
0x03,0x0d,0x00,0x09,0x06,0x03,0x03,0x0d,0x00,0x09,0x0f,0x03,0x03,0x0d,0x00,0x09,
0x18,0x03,0x03,0x0d,0x00,0x09,0x21,0x03,0x03,0x0d,0x00,0x09,0x2a,0x03,0x03,0x0d,
0x00,0x09,0x33,0x03,0x02,0x0e,0x00,0x09,0x3c,0x03,0x02,0x0e,0x00,0x09,0x45,0x03,
0x02,0x0e,0x00,0x09,0x4e,0x03,0x04,0x0b,0x00,0x09,0x57,0x03,0x0d,0x0e,0x00,0x09,
0x60,0x03,0x02,0x06,0x00,0x09,0x69,0x03,0x05,0x0d,0x00,0x09,0x72,0x03,0x02,0x0d,
0x00,0x09,0x7b,0x03,0x05,0x0d,0x00,0x09,0x84,0x03,0x02,0x0d,0x00,0x09,0x8d,0x03,
0x05,0x0d,0x00,0x09,0x96,0x03,0x02,0x0d,0x00,0x09,0x9f,0x03,0x05,0x0f,0x00,0x09,
0xa8,0x03,0x02,0x0d,0x00,0x09,0xb1,0x03,0x02,0x0d,0x00,0x09,0xba,0x03,0x02,0x0f,
0x00,0x09,0xc3,0x03,0x02,0x0d,0x00,0x09,0xcc,0x03,0x02,0x0d,0x00,0x09,0xd5,0x03,
0x05,0x0d,0x00,0x09,0xde,0x03,0x05,0x0d,0x00,0x09,0xe7,0x03,0x05,0x0d,0x00,0x09,
0xf0,0x03,0x05,0x0f,0x00,0x09,0xf9,0x03,0x05,0x0f,0x00,0x09,0x02,0x04,0x05,0x0d,
0x00,0x09,0x0b,0x04,0x05,0x0d,0x00,0x09,0x14,0x04,0x03,0x0d,0x00,0x09,0x1d,0x04,
0x05,0x0d,0x00,0x09,0x26,0x04,0x05,0x0d,0x00,0x09,0x2f,0x04,0x05,0x0d,0x00,0x09,
0x38,0x04,0x05,0x0d,0x00,0x09,0x41,0x04,0x05,0x0f,0x00,0x09,0x4a,0x04,0x05,0x0d,
0x00,0x09,0x53,0x04,0x02,0x0e,0x00,0x09,0x5c,0x04,0x02,0x0e,0x00,0x09,0x65,0x04,
0x02,0x0e,0x00,0x09,0x6e,0x04,0x07,0x0a,0x00,0x09,0x77,0x04,0x01,0x0d,0x00,0x09,
0x80,0x04,0x00,0x0e,0x00,0x09,0x89,0x04,0x00,0x0f,0x00,0x09,0x92,0x04,0x00,0x0f,
0x00,0x09,0x9b,0x04,0x00,0x0f,0x00,0x09,0xa4,0x04,0x00,0x0f,0x00,0x09,0xad,0x04,
0x00,0x0f,0x00,0x09,0xb6,0x04,0x00,0x0f,0x00,0x09,0xbf,0x04,0x00,0x0f,0x00,0x09,
0xc8,0x04,0x00,0x0f,0x00,0x09,0xd1,0x04,0x00,0x0f,0x00,0x09,0xda,0x04,0x00,0x0f,
0x00,0x09,0xe3,0x04,0x00,0x0f,0x00,0x09,0xec,0x04,0x00,0x0f,0x00,0x09,0xf5,0x04,
0x00,0x0f,0x00,0x09,0xfe,0x04,0x00,0x0f,0x00,0x09,0x07,0x05,0x00,0x0f,0x00,0x09,
0x10,0x05,0x00,0x0f,0x00,0x09,0x19,0x05,0x00,0x0f,0x00,0x09,0x22,0x05,0x00,0x0f,
0x00,0x09,0x2b,0x05,0x00,0x0f,0x00,0x09,0x34,0x05,0x00,0x0f,0x00,0x09,0x3d,0x05,
0x00,0x0f,0x00,0x09,0x46,0x05,0x00,0x0f,0x00,0x09,0x4f,0x05,0x00,0x0f,0x00,0x09,
0x58,0x05,0x00,0x0f,0x00,0x09,0x61,0x05,0x00,0x0f,0x00,0x09,0x6a,0x05,0x00,0x0f,
0x00,0x09,0x73,0x05,0x00,0x0f,0x00,0x09,0x7c,0x05,0x00,0x0f,0x00,0x09,0x85,0x05,
0x00,0x0f,0x00,0x09,0x8e,0x05,0x00,0x0f,0x00,0x09,0x97,0x05,0x00,0x0f,0x00,0x09,
0xa0,0x05,0x00,0x0d,0x00,0x09,0xa9,0x05,0x05,0x0f,0x00,0x09,0xb2,0x05,0x02,0x0e,
0x00,0x09,0xbb,0x05,0x03,0x0d,0x00,0x09,0xc4,0x05,0x03,0x0d,0x00,0x09,0xcd,0x05,
0x03,0x0d,0x00,0x09,0xd6,0x05,0x02,0x0e,0x00,0x09,0xdf,0x05,0x03,0x0e,0x00,0x09,
0xe8,0x05,0x02,0x04,0x00,0x09,0xf1,0x05,0x03,0x0d,0x00,0x09,0xfa,0x05,0x03,0x0a,
0x00,0x09,0x03,0x06,0x06,0x0b,0x00,0x09,0x0c,0x06,0x07,0x0a,0x00,0x09,0x15,0x06,
0x08,0x09,0x00,0x09,0x1e,0x06,0x03,0x0b,0x00,0x09,0x27,0x06,0x02,0x03,0x00,0x09,
0x30,0x06,0x03,0x07,0x00,0x09,0x39,0x06,0x05,0x0c,0x00,0x09,0x42,0x06,0x03,0x0a,
0x00,0x09,0x4b,0x06,0x03,0x0a,0x00,0x09,0x54,0x06,0x02,0x04,0x00,0x09,0x5d,0x06,
0x05,0x0f,0x00,0x09,0x66,0x06,0x03,0x0e,0x00,0x09,0x6f,0x06,0x08,0x0a,0x00,0x09,
0x78,0x06,0x0d,0x0f,0x00,0x09,0x81,0x06,0x03,0x0a,0x00,0x09,0x8a,0x06,0x03,0x0a,
0x00,0x09,0x93,0x06,0x06,0x0b,0x00,0x09,0x9c,0x06,0x03,0x0d,0x00,0x09,0xa5,0x06,
0x03,0x0d,0x00,0x09,0xae,0x06,0x03,0x0d,0x00,0x09,0xb7,0x06,0x05,0x0f,0x00,0x09,
0xc0,0x06,0x00,0x0d,0x00,0x09,0xc9,0x06,0x00,0x0d,0x00,0x09,0xd2,0x06,0x00,0x0d,
0x00,0x09,0xdb,0x06,0x00,0x0d,0x00,0x09,0xe4,0x06,0x00,0x0d,0x00,0x09,0xed,0x06,
0x01,0x0d,0x00,0x09,0xf6,0x06,0x03,0x0d,0x00,0x09,0xff,0x06,0x03,0x0f,0x00,0x09,
0x08,0x07,0x00,0x0d,0x00,0x09,0x11,0x07,0x00,0x0d,0x00,0x09,0x1a,0x07,0x00,0x0d,
0x00,0x09,0x23,0x07,0x00,0x0d,0x00,0x09,0x2c,0x07,0x00,0x0d,0x00,0x09,0x35,0x07,
0x00,0x0d,0x00,0x09,0x3e,0x07,0x00,0x0d,0x00,0x09,0x47,0x07,0x00,0x0d,0x00,0x09,
0x50,0x07,0x03,0x0d,0x00,0x09,0x59,0x07,0x00,0x0d,0x00,0x09,0x62,0x07,0x00,0x0d,
0x00,0x09,0x6b,0x07,0x00,0x0d,0x00,0x09,0x74,0x07,0x00,0x0d,0x00,0x09,0x7d,0x07,
0x00,0x0d,0x00,0x09,0x86,0x07,0x00,0x0d,0x00,0x09,0x8f,0x07,0x06,0x0b,0x00,0x09,
0x98,0x07,0x03,0x0d,0x00,0x09,0xa1,0x07,0x00,0x0d,0x00,0x09,0xaa,0x07,0x00,0x0d,
0x00,0x09,0xb3,0x07,0x00,0x0d,0x00,0x09,0xbc,0x07,0x00,0x0d,0x00,0x09,0xc5,0x07,
0x00,0x0d,0x00,0x09,0xce,0x07,0x03,0x0d,0x00,0x09,0xd7,0x07,0x02,0x0d,0x00,0x09,
0xe0,0x07,0x02,0x0d,0x00,0x09,0xe9,0x07,0x02,0x0d,0x00,0x09,0xf2,0x07,0x02,0x0d,
0x00,0x09,0xfb,0x07,0x02,0x0d,0x00,0x09,0x04,0x08,0x02,0x0d,0x00,0x09,0x0d,0x08,
0x02,0x0d,0x00,0x09,0x16,0x08,0x05,0x0d,0x00,0x09,0x1f,0x08,0x05,0x0f,0x00,0x09,
0x28,0x08,0x02,0x0d,0x00,0x09,0x31,0x08,0x02,0x0d,0x00,0x09,0x3a,0x08,0x02,0x0d,
0x00,0x09,0x43,0x08,0x02,0x0d,0x00,0x09,0x4c,0x08,0x02,0x0d,0x00,0x09,0x55,0x08,
0x02,0x0d,0x00,0x09,0x5e,0x08,0x02,0x0d,0x00,0x09,0x67,0x08,0x02,0x0d,0x00,0x09,
0x70,0x08,0x02,0x0d,0x00,0x09,0x79,0x08,0x02,0x0d,0x00,0x09,0x82,0x08,0x02,0x0d,
0x00,0x09,0x8b,0x08,0x02,0x0d,0x00,0x09,0x94,0x08,0x02,0x0d,0x00,0x09,0x9d,0x08,
0x02,0x0d,0x00,0x09,0xa6,0x08,0x02,0x0d,0x00,0x09,0xaf,0x08,0x05,0x0c,0x00,0x09,
0xb8,0x08,0x05,0x0d,0x00,0x09,0xc1,0x08,0x02,0x0d,0x00,0x09,0xca,0x08,0x02,0x0d,
0x00,0x09,0xd3,0x08,0x02,0x0d,0x00,0x09,0xdc,0x08,0x02,0x0d,0x00,0x09,0xe5,0x08,
0x02,0x0f,0x00,0x09,0xee,0x08,0x03,0x0f,0x00,0x09,0xf7,0x08,0x02,0x0f,0x00,0x09,
0x00,0x09,0x00,0x00,0x00,0x00,
};

int	sizeofdefont = sizeof defontdata;

void
_unpackinfo(Fontchar *fc, uchar *p, int n)
{
	int j;

	for(j=0;  j<=n;  j++){
		fc->x = p[0]|(p[1]<<8);
		fc->top = p[2];
		fc->bottom = p[3];
		fc->left = p[4];
		fc->width = p[5];
		fc++;
		p += 6;
	}
}
