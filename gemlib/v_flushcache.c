/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** 
 *
 *  @param handle Device handle
 *
 *  @return 
 *
 *  @since 
 *
 *  @sa
 *
 *
 *
 */

short
v_flushcache (short handle)
{
#if USE_LOCAL_VDIPB
	/* todo (doc wanted) */
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_intout[VDI_INTOUTMAX]; 
	short vdi_ptsout[VDI_PTSOUTMAX]; 
	VDI_PARAMS(vdi_control, 0L, 0L, vdi_intout, vdi_ptsout );
#endif
	
	VDI_TRAP_00 (vdi_params, handle, 251);
	
	return vdi_intout[0];
}
