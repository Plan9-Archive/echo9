/* 
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include	"l.h"

/* note: not finished
 *	movd	fr,mem
 *	movd	mem,fr
 *	addv
 *	addvu
 *	subv
 *	subvu
 *	mulv
 *	mulvu
 *	divv
 *	divvu
 *	remv
 *	remvu
 */

#define	X	99

Optab	optab[] =
{
	{ ATEXT,	C_LEXT,	C_NONE,	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_LEXT,	C_REG,	C_LCON, 	 0, 0, 0 },

	{ AMOVW,	C_REG,	C_NONE,	C_REG,		 1, 4, 0 },
	{ AMOVV,	C_REG,	C_NONE,	C_REG,		 1, 4, 0 },
	{ AMOVB,	C_REG,	C_NONE,	C_REG,		12, 8, 0 },
	{ AMOVBU,	C_REG,	C_NONE,	C_REG,		13, 4, 0 },

	{ ASUB,		C_REG,	C_REG,	C_REG,		 2, 4, 0 },
	{ AADD,		C_REG,	C_REG,	C_REG,		 2, 4, 0 },
	{ AAND,		C_REG,	C_REG,	C_REG,		 2, 4, 0 },
	{ ASUB,		C_REG,	C_NONE,	C_REG,		 2, 4, 0 },
	{ AADD,		C_REG,	C_NONE,	C_REG,		 2, 4, 0 },
	{ AAND,		C_REG,	C_NONE,	C_REG,		 2, 4, 0 },

	{ ASLL,		C_REG,	C_NONE,	C_REG,		 9, 4, 0 },
	{ ASLL,		C_REG,	C_REG,	C_REG,		 9, 4, 0 },

	{ AADDF,	C_FREG,	C_NONE,	C_FREG,		32, 4, 0 },
	{ AADDF,	C_FREG,	C_REG,	C_FREG,		32, 4, 0 },
	{ ACMPEQF,	C_FREG,	C_REG,	C_NONE,		32, 4, 0 },
	{ AABSF,	C_FREG,	C_NONE,	C_FREG,		33, 4, 0 },
	{ AMOVF,	C_FREG,	C_NONE,	C_FREG,		33, 4, 0 },
	{ AMOVD,	C_FREG,	C_NONE,	C_FREG,		33, 4, 0 },

	{ AMOVW,	C_REG,	C_NONE,	C_SEXT,		 7, 4, REGSB },
	{ AMOVV,	C_REG,	C_NONE,	C_SEXT,		 7, 4, REGSB },
	{ AMOVB,	C_REG,	C_NONE,	C_SEXT,		 7, 4, REGSB },
	{ AMOVBU,	C_REG,	C_NONE,	C_SEXT,		 7, 4, REGSB },
	{ AMOVWL,	C_REG,	C_NONE,	C_SEXT,		 7, 4, REGSB },
	{ AMOVW,	C_REG,	C_NONE,	C_SAUTO,	 7, 4, REGSP },
	{ AMOVV,	C_REG,	C_NONE,	C_SAUTO,	 7, 4, REGSP },
	{ AMOVB,	C_REG,	C_NONE,	C_SAUTO,	 7, 4, REGSP },
	{ AMOVBU,	C_REG,	C_NONE,	C_SAUTO,	 7, 4, REGSP },
	{ AMOVWL,	C_REG,	C_NONE,	C_SAUTO,	 7, 4, REGSP },
	{ AMOVW,	C_REG,	C_NONE,	C_SOREG,	 7, 4, REGZERO },
	{ AMOVV,	C_REG,	C_NONE,	C_SOREG,	 7, 4, REGZERO },
	{ AMOVB,	C_REG,	C_NONE,	C_SOREG,	 7, 4, REGZERO },
	{ AMOVBU,	C_REG,	C_NONE,	C_SOREG,	 7, 4, REGZERO },
	{ AMOVWL,	C_REG,	C_NONE,	C_SOREG,	 7, 4, REGZERO },

	{ AMOVW,	C_SEXT,	C_NONE,	C_REG,		 8, 4, REGSB },
	{ AMOVV,	C_SEXT,	C_NONE,	C_REG,		 8, 4, REGSB },
	{ AMOVB,	C_SEXT,	C_NONE,	C_REG,		 8, 4, REGSB },
	{ AMOVBU,	C_SEXT,	C_NONE,	C_REG,		 8, 4, REGSB },
	{ AMOVWL,	C_SEXT,	C_NONE,	C_REG,		 8, 4, REGSB },
	{ AMOVW,	C_SAUTO,C_NONE,	C_REG,		 8, 4, REGSP },
	{ AMOVV,	C_SAUTO,C_NONE,	C_REG,		 8, 4, REGSP },
	{ AMOVB,	C_SAUTO,C_NONE,	C_REG,		 8, 4, REGSP },
	{ AMOVBU,	C_SAUTO,C_NONE,	C_REG,		 8, 4, REGSP },
	{ AMOVWL,	C_SAUTO,C_NONE,	C_REG,		 8, 4, REGSP },
	{ AMOVW,	C_SOREG,C_NONE,	C_REG,		 8, 4, REGZERO },
	{ AMOVV,	C_SOREG,C_NONE,	C_REG,		 8, 4, REGZERO },
	{ AMOVB,	C_SOREG,C_NONE,	C_REG,		 8, 4, REGZERO },
	{ AMOVBU,	C_SOREG,C_NONE,	C_REG,		 8, 4, REGZERO },
	{ AMOVWL,	C_SOREG,C_NONE,	C_REG,		 8, 4, REGZERO },

	{ AMOVW,	C_REG,	C_NONE,	C_LEXT,		35, 16, REGSB },
	{ AMOVV,	C_REG,	C_NONE,	C_LEXT,		35, 16, REGSB },
	{ AMOVB,	C_REG,	C_NONE,	C_LEXT,		35, 16, REGSB },
	{ AMOVBU,	C_REG,	C_NONE,	C_LEXT,		35, 16, REGSB },
	{ AMOVW,	C_REG,	C_NONE,	C_LAUTO,	35, 16, REGSP },
	{ AMOVV,	C_REG,	C_NONE,	C_LAUTO,	35, 16, REGSP },
	{ AMOVB,	C_REG,	C_NONE,	C_LAUTO,	35, 16, REGSP },
	{ AMOVBU,	C_REG,	C_NONE,	C_LAUTO,	35, 16, REGSP },
	{ AMOVW,	C_REG,	C_NONE,	C_LOREG,	35, 16, REGZERO },
	{ AMOVV,	C_REG,	C_NONE,	C_LOREG,	35, 16, REGZERO },
	{ AMOVB,	C_REG,	C_NONE,	C_LOREG,	35, 16, REGZERO },
	{ AMOVBU,	C_REG,	C_NONE,	C_LOREG,	35, 16, REGZERO },

	{ AMOVW,	C_LEXT,	C_NONE,	C_REG,		36, 16, REGSB },
	{ AMOVV,	C_LEXT,	C_NONE,	C_REG,		36, 16, REGSB },
	{ AMOVB,	C_LEXT,	C_NONE,	C_REG,		36, 16, REGSB },
	{ AMOVBU,	C_LEXT,	C_NONE,	C_REG,		36, 16, REGSB },
	{ AMOVW,	C_LAUTO,C_NONE,	C_REG,		36, 16, REGSP },
	{ AMOVV,	C_LAUTO,C_NONE,	C_REG,		36, 16, REGSP },
	{ AMOVB,	C_LAUTO,C_NONE,	C_REG,		36, 16, REGSP },
	{ AMOVBU,	C_LAUTO,C_NONE,	C_REG,		36, 16, REGSP },
	{ AMOVW,	C_LOREG,C_NONE,	C_REG,		36, 16, REGZERO },
	{ AMOVV,	C_LOREG,C_NONE,	C_REG,		36, 16, REGZERO },
	{ AMOVB,	C_LOREG,C_NONE,	C_REG,		36, 16, REGZERO },
	{ AMOVBU,	C_LOREG,C_NONE,	C_REG,		36, 16, REGZERO },

	{ AMOVW,	C_SECON,C_NONE,	C_REG,		 3, 4, REGSB },
	{ AMOVW,	C_SACON,C_NONE,	C_REG,		 3, 4, REGSP },
	{ AMOVW,	C_LECON,C_NONE,	C_REG,		26, 12, REGSB },
	{ AMOVW,	C_LACON,C_NONE,	C_REG,		26, 12, REGSP },
	{ AMOVW,	C_ADDCON,C_NONE,C_REG,		 3, 4, REGZERO },
	{ AMOVW,	C_ANDCON,C_NONE,C_REG,		 3, 4, REGZERO },

	{ AMOVW,	C_UCON, C_NONE, C_REG,		24, 4, 0 },
	{ AMOVW,	C_LCON,	C_NONE,	C_REG,		19, 8, 0 },

	{ AMOVW,	C_HI,	C_NONE,	C_REG,		20, 4, 0 },
	{ AMOVV,	C_HI,	C_NONE,	C_REG,		20, 4, 0 },
	{ AMOVW,	C_LO,	C_NONE,	C_REG,		20, 4, 0 },
	{ AMOVV,	C_LO,	C_NONE,	C_REG,		20, 4, 0 },
	{ AMOVW,	C_REG,	C_NONE,	C_HI,		21, 4, 0 },
	{ AMOVV,	C_REG,	C_NONE,	C_HI,		21, 4, 0 },
	{ AMOVW,	C_REG,	C_NONE,	C_LO,		21, 4, 0 },
	{ AMOVV,	C_REG,	C_NONE,	C_LO,		21, 4, 0 },

	{ AMUL,		C_REG,	C_REG,	C_NONE,		22, 4, 0 },

	{ AADD,		C_ADD0CON,C_REG,C_REG,		 4, 4, 0 },
	{ AADD,		C_ADD0CON,C_NONE,C_REG,		 4, 4, 0 },
	{ AADD,		C_ANDCON,C_REG,	C_REG,		10, 8, 0 },
	{ AADD,		C_ANDCON,C_NONE,C_REG,		10, 8, 0 },

	{ AAND,		C_AND0CON,C_REG,C_REG,		 4, 4, 0 },
	{ AAND,		C_AND0CON,C_NONE,C_REG,		 4, 4, 0 },
	{ AAND,		C_ADDCON,C_REG,	C_REG,		10, 8, 0 },
	{ AAND,		C_ADDCON,C_NONE,C_REG,		10, 8, 0 },

	{ AADD,		C_UCON,	C_REG,	C_REG,		25, 8, 0 },
	{ AADD,		C_UCON,	C_NONE,	C_REG,		25, 8, 0 },
	{ AAND,		C_UCON,	C_REG,	C_REG,		25, 8, 0 },
	{ AAND,		C_UCON,	C_NONE,	C_REG,		25, 8, 0 },

	{ AADD,		C_LCON,	C_NONE,	C_REG,		23, 12, 0 },
	{ AAND,		C_LCON,	C_NONE,	C_REG,		23, 12, 0 },
	{ AADD,		C_LCON,	C_REG,	C_REG,		23, 12, 0 },
	{ AAND,		C_LCON,	C_REG,	C_REG,		23, 12, 0 },

	{ ASLL,		C_SCON,	C_REG,	C_REG,		16, 4, 0 },
	{ ASLL,		C_SCON,	C_NONE,	C_REG,		16, 4, 0 },

	{ ASYSCALL,	C_NONE,	C_NONE,	C_NONE,		 5, 4, 0 },

	{ ABEQ,		C_REG,	C_REG,	C_SBRA,		 6, 4, 0 },
	{ ABEQ,		C_REG,	C_NONE,	C_SBRA,		 6, 4, 0 },
	{ ABLEZ,	C_REG,	C_NONE,	C_SBRA,		 6, 4, 0 },
	{ ABFPT,	C_NONE,	C_NONE,	C_SBRA,		 6, 4, 0 },

	{ AJMP,		C_NONE,	C_NONE,	C_LBRA,		11, 4, 0 },
	{ AJAL,		C_NONE,	C_NONE,	C_LBRA,		11, 4, 0 },

	{ AJMP,		C_NONE,	C_NONE,	C_ZOREG,	18, 4, REGZERO },
	{ AJAL,		C_NONE,	C_NONE,	C_ZOREG,	18, 4, REGLINK },

	{ AMOVW,	C_SEXT,	C_NONE,	C_FREG,		27, 4, REGSB },
	{ AMOVF,	C_SEXT,	C_NONE,	C_FREG,		27, 4, REGSB },
	{ AMOVD,	C_SEXT,	C_NONE,	C_FREG,		27, 8, REGSB },
	{ AMOVW,	C_SAUTO,C_NONE,	C_FREG,		27, 4, REGSP },
	{ AMOVF,	C_SAUTO,C_NONE,	C_FREG,		27, 4, REGSP },
	{ AMOVD,	C_SAUTO,C_NONE,	C_FREG,		27, 8, REGSP },
	{ AMOVW,	C_SOREG,C_NONE,	C_FREG,		27, 4, REGZERO },
	{ AMOVF,	C_SOREG,C_NONE,	C_FREG,		27, 4, REGZERO },
	{ AMOVD,	C_SOREG,C_NONE,	C_FREG,		27, 8, REGZERO },

	{ AMOVW,	C_LEXT,	C_NONE,	C_FREG,		27, 16, REGSB },
	{ AMOVF,	C_LEXT,	C_NONE,	C_FREG,		27, 16, REGSB },
	{ AMOVD,	C_LEXT,	C_NONE,	C_FREG,		27, 20, REGSB },
	{ AMOVW,	C_LAUTO,C_NONE,	C_FREG,		27, 16, REGSP },
	{ AMOVF,	C_LAUTO,C_NONE,	C_FREG,		27, 16, REGSP },
	{ AMOVD,	C_LAUTO,C_NONE,	C_FREG,		27, 20, REGSP },
	{ AMOVW,	C_LOREG,C_NONE,	C_FREG,		27, 16, REGZERO },
	{ AMOVF,	C_LOREG,C_NONE,	C_FREG,		27, 16, REGZERO },
	{ AMOVD,	C_LOREG,C_NONE,	C_FREG,		27, 20, REGZERO },

	{ AMOVW,	C_FREG,	C_NONE,	C_SEXT,		28, 4, REGSB },
	{ AMOVF,	C_FREG,	C_NONE,	C_SEXT,		28, 4, REGSB },
	{ AMOVD,	C_FREG,	C_NONE,	C_SEXT,		28, 8, REGSB },
	{ AMOVW,	C_FREG,	C_NONE,	C_SAUTO,	28, 4, REGSP },
	{ AMOVF,	C_FREG,	C_NONE,	C_SAUTO,	28, 4, REGSP },
	{ AMOVD,	C_FREG,	C_NONE,	C_SAUTO,	28, 8, REGSP },
	{ AMOVW,	C_FREG,	C_NONE,	C_SOREG,	28, 4, REGZERO },
	{ AMOVF,	C_FREG,	C_NONE,	C_SOREG,	28, 4, REGZERO },
	{ AMOVD,	C_FREG,	C_NONE,	C_SOREG,	28, 8, REGZERO },

	{ AMOVW,	C_FREG,	C_NONE,	C_LEXT,		28, 16, REGSB },
	{ AMOVF,	C_FREG,	C_NONE,	C_LEXT,		28, 16, REGSB },
	{ AMOVD,	C_FREG,	C_NONE,	C_LEXT,		28, 20, REGSB },
	{ AMOVW,	C_FREG,	C_NONE,	C_LAUTO,	28, 16, REGSP },
	{ AMOVF,	C_FREG,	C_NONE,	C_LAUTO,	28, 16, REGSP },
	{ AMOVD,	C_FREG,	C_NONE,	C_LAUTO,	28, 20, REGSP },
	{ AMOVW,	C_FREG,	C_NONE,	C_LOREG,	28, 16, REGZERO },
	{ AMOVF,	C_FREG,	C_NONE,	C_LOREG,	28, 16, REGZERO },
	{ AMOVD,	C_FREG,	C_NONE,	C_LOREG,	28, 20, REGZERO },

	{ AMOVW,	C_REG,	C_NONE,	C_FREG,		30, 4, 0 },
	{ AMOVW,	C_FREG,	C_NONE,	C_REG,		31, 4, 0 },

	{ AMOVW,	C_ADDCON,C_NONE,C_FREG,		34, 8, 0 },
	{ AMOVW,	C_ANDCON,C_NONE,C_FREG,		34, 8, 0 },
	{ AMOVW,	C_UCON, C_NONE, C_FREG,		35, 8, 0 },
	{ AMOVW,	C_LCON,	C_NONE,	C_FREG,		36, 12, 0 },

	{ AMOVW,	C_REG,	C_NONE,	C_MREG,		37, 4, 0 },
	{ AMOVV,	C_REG,	C_NONE,	C_MREG,		37, 4, 0 },
	{ AMOVW,	C_MREG,	C_NONE,	C_REG,		38, 4, 0 },
	{ AMOVV,	C_MREG,	C_NONE,	C_REG,		38, 4, 0 },

	{ ARFE,		C_NONE,	C_NONE,	C_ZOREG,	39, 8, 0 },
	{ AWORD,	C_NONE,	C_NONE,	C_LCON,		40, 4, 0 },

	{ AMOVW,	C_REG,	C_NONE,	C_FCREG,	41, 8, 0 },
	{ AMOVV,	C_REG,	C_NONE,	C_FCREG,	41, 8, 0 },
	{ AMOVW,	C_FCREG,C_NONE,	C_REG,		42, 4, 0 },
	{ AMOVV,	C_FCREG,C_NONE,	C_REG,		42, 4, 0 },

	{ ABREAK,	C_REG,	C_NONE,	C_SEXT,		 7, 4, REGSB },	/* really CACHE instruction */
	{ ABREAK,	C_REG,	C_NONE,	C_SAUTO,	 7, 4, REGSP },
	{ ABREAK,	C_REG,	C_NONE,	C_SOREG,	 7, 4, REGZERO },
	{ ABREAK,	C_NONE,	C_NONE,	C_NONE,		 5, 4, 0 },

	{ ACASE,	C_REG,	C_NONE,	C_NONE,		 45, 28, 0 },
	{ ABCASE,	C_LCON,	C_NONE,	C_LBRA,		 46, 4, 0 },

	{ AXXX,		C_NONE,	C_NONE,	C_NONE,		 0, 4, 0 },
};
