/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** This function moves the cursor to the upper left character cell
 *
 *  @param handle Device handle
 *
 *  @since all VDI versions
 *
 */

void
v_curhome (short handle)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	VDIPB vdi_params =               
	{                                
		&vdi_control[0],             /* vdi_control */
		0L, 						 /* vdi_intin	*/
		0L, 						 /* vdi_ptsin	*/
		0L, 						 /* vdi_intout  */
		0L							 /* vdi_ptsout  */
	};
#endif
	
	VDI_TRAP_ESC (vdi_params, handle, 5,8, 0,0);
}
