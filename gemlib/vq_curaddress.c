/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** This call returns the current cursor position
 *
 *  @param handle Device handle
 *  @param cur_row (1 to the maximum number of rows)
 *  @param cur_col (1 to the maximum number of columns)
 *
 *  @since all VDI versions
 *
 */

void
vq_curaddress (short handle, short *cur_row, short *cur_col)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_intout[2]; 
	VDI_PARAMS(vdi_control, 0L, 0L, vdi_intout, 0L );
#endif
	
	VDI_TRAP_ESC (vdi_params, handle, 5,15, 0,0);
	
	*cur_row = vdi_intout[0];
	*cur_col = vdi_intout[1];
}
