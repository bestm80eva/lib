/*
 *  $Id$
 */

#include "gem_vdiP.h"
#include "vdi_userdef.h"

/** UDEF version of v_alpha_text(). See \ref overviewUDEF for details about UDEF feature
 */

void
udef_v_alpha_text (short handle, const char *str)
{
	short n = vdi_str2array_n (str, _VDIParBlk.vdi_intin, VDI_INTINMAX);

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, 0L, _VDIParBlk.vdi_intout, vdi_dummy);
	
	VDI_TRAP_ESC (vdi_params, handle, 5,25, 0,n);
}
