#include "gem_vdiP.h"


void
v_justified (short handle, short x, short y,
             const char *str, short len, short word_space, short char_space)
{
	register short n = 2 + vdi_str2array (str, vdi_intin + 2);

	vdi_intin[0] = word_space;
	vdi_intin[1] = char_space;
	vdi_ptsin[0] = x;
	vdi_ptsin[1] = y;
	vdi_ptsin[2] = len;
	vdi_ptsin[3] = 0;

	VDI_TRAP_ESC (vdi_params, handle, 11,10, 2,n);
}
