/*
 *  $Id$
 */

#include "gem_vdiP.h"
#include "vdi_userdef.h"


/** UDEF version of v_gtext(). See \ref overviewUDEF for details about UDEF feature
 */

void
udef_v_gtext (short handle, short x, short y, const char *str)
{
	short n = vdi_str2array_n (str, _VDIParBlk.vdi_intin, VDI_INTINMAX);

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, _VDIParBlk.vdi_ptsin, vdi_dummy, vdi_dummy );

	_VDIParBlk.vdi_ptsin[0]     = x;
	_VDIParBlk.vdi_ptsin[1]     = y;
	
	VDI_TRAP (vdi_params, handle, 8, 1,n);
}
