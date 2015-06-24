/* 
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "astro.h"

double	sunfp[]	=
{
	-.265, 0,
	3.760, 0,
	 .200, 0,
	0,

	-.021, 0,
	5.180, 0,
	1.882, 3.8991,
	-.030, 0,
	0,

	0.075, 5.1766,
	4.838, 5.2203,
	0.074, 3.6285,
	0.116, 2.5988,
	5.526, 2.5885,
	2.497, 5.5143,
	0.044, 5.4350,
	0.666, 3.1016,
	1.559, 6.0258,
	1.024, 5.5527,
	0.210, 3.5989,
	0.144, 3.4104,
	0.152, 6.0004,
	0.084, 4.1120,
	0.037, 3.8711,
	0.123, 3.4086,
	0.154, 6.2762,
	0.038, 4.6094,
	0.020, 5.1313,
	0.042, 4.5239,
	0.032, 0.8517,
	0.273, 3.7996,
	0.048, 4.5431,
	0.041, 6.0388,
	2.043, 6.0020,
	1.770, 3.4977,
	0.028, 2.5831,
	0.129, 5.1348,
	0.425, 5.9146,
	0.034, 1.2391,
	0.500, 1.8357,
	0.585, 5.8304,
	0.085, 0.9529,
	0.204, 1.7593,
	0.020, 3.2463,
	0.154, 3.9689,
	0.101, 1.6808,
	0.049, 3.0805,
	0.106, 3.8868,
	0.052, 6.0895,
	0.021, 3.7559,
	0.028, 5.2011,
	0.062, 6.0388,
	0.044, 1.8483,
	0.045, 3.9759,
	0.021, 5.3931,
	0.026, 1.9722,
	0.163, 3.4662,
	7.208, 3.1334,
	2.600, 4.5940,
	0.073, 4.8223,
	0.069, 1.4102,
	2.731, 1.5210,
	1.610, 1.9110,
	0.073, 4.4087,
	0.164, 2.9758,
	0.556, 1.4425,
	0.210, 1.7261,
	0.044, 2.9356,
	0.080, 1.3561,
	0.419, 1.7555,
	0.320, 4.7030,
	0.108, 5.0719,
	0.112, 5.1243,
	0.021, 5.0440,
	0,

	6.454, 0,
	0.177, 0,
	-.424, 0,
	0.039, 0,
	-.064, 0,
	0.172, 0,
	0,

	-.092, 1.6354,
	-.067, 2.1468,
	-.210, 2.6494,
	-.166, 4.6338,
	0,

	0.576, 0,
	-.047, 0,
	0.021, 0,
	0,

	2.359e-6, 3.6607,
	6.842e-6, 1.0180,
	0.869e-6, 3.9567,
	1.045e-6, 1.5332,
	1.497e-6, 4.4691,
	0.376e-6, 2.0295,
	2.057e-6, 4.0941,
	0.215e-6, 4.3459,
	0.478e-6, 0.2648,
	0.208e-6, 1.9548,
	7.067e-6, 1.5630,
	0.244e-6, 5.9097,
	4.026e-6, 6.2526,
	1.459e-6, 0.3409,
	0.281e-6, 1.4172,
	0.803e-6, 6.1533,
	0.429e-6, 0.1850,
	0,

	13.36e-6, 0,
	-1.33e-6, 0,
	 0.37e-6, 0,
	 0.36e-6, 0,
	0,
};
char	suncp[]	=
{
	4, -7, 3, 0,
	-8, 4, 0, 3,
	15, -8, 0, 0,

	4, -7, 3, 0, 0,
	-8, 4, 0, 3, 0,
	0, 13, -8, 0, 1,
	15, -8, 0, 0, 0,

	0,0,1,0,0,
	0,-1,1,0,0,
	0,-2,1,0,0,
	0,-1,2,0,0,
	0,-2,2,0,0,
	0,-3,2,0,0,
	0,-4,2,0,0,
	0,-3,3,0,0,
	0,-4,3,0,0,
	0,-5,3,0,0,
	0,-4,4,0,0,
	0,-5,4,0,0,
	0,-6,4,0,0,
	0,-5,5,0,0,
	0,-6,5,0,0,
	0,-7,5,0,0,
	0,-8,5,0,0,
	0,-6,6,0,0,
	0,-7,7,0,0,
	0,-12,8,0,0,
	0,-14,8,0,0,
	-1,1,0,0,0,
	-1,0,0,0,0,
	-2,3,0,0,0,
	-2,2,0,0,0,
	-2,1,0,0,0,
	-2,0,0,0,0,
	-3,3,0,0,0,
	-3,2,0,0,0,
	-4,4,0,0,0,
	-4,3,0,0,0,
	-4,2,0,0,0,
	-5,4,0,0,0,
	-5,3,0,0,0,
	-6,5,0,0,0,
	-6,4,0,0,0,
	-6,3,0,0,0,
	-7,5,0,0,0,
	-7,4,0,0,0,
	-8,5,0,0,0,
	-8,4,0,0,0,
	-9,6,0,0,0,
	-9,5,0,0,0,
	-11,6,0,0,0,
	-13,7,0,0,0,
	-15,9,0,0,0,
	-17,9,0,0,0,
	0,2,0,-1,0,
	0,1,0,-1,0,
	0,0,0,-1,0,
	0,-1,0,-1,0,
	0,3,0,-2,0,
	0,2,0,-2,0,
	0,1,0,-2,0,
	0,0,0,-2,0,
	0,3,0,-3,0,
	0,2,0,-3,0,
	0,1,0,-3,0,
	0,3,0,-4,0,
	0,2,0,-4,0,
	0,1,0,0,-1,
	0,0,0,0,-1,
	0,2,0,0,-2,
	0,1,0,0,-2,
	0,2,0,0,-3,

	1,0,0,
	1,1,0,
	1,-1,0,
	3,-1,0,
	1,0,1,
	1,0,-1,

	-2,1,0,
	-3,2,0,
	-4,2,0,
	1,0,-2,

	1,0,0,
	1,-1,0,
	-1,0,2,

	0,-1,1,0,0,
	0,-2,2,0,0,
	0,-3,2,0,0,
	0,-3,3,0,0,
	0,-4,3,0,0,
	0,-4,4,0,0,
	-2,2,0,0,0,
	-3,2,0,0,0,
	-4,3,0,0,0,
	0,2,0,-1,0,
	0,1,0,-1,0,
	0,0,0,-1,0,
	0,2,0,-2,0,
	0,1,0,-2,0,
	0,3,0,-3,0,
	0,2,0,-3,0,
	0,1,0,0,-1,

	1,0,0,
	1,-1,0,
	1,1,0,
	1,0,-1,
};
