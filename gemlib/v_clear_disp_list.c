/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** This function for printer or plotter drivers clears the printing buffer 
 *  (and deletes all previous commands). In contrast to v_clrwk() it does 
 *  not advance the page.
 *
 *  @param handle Device handle
 *
 *  @since all VDI versions
 *
 *  This function should be called if the user interrupts printing while your 
 *  application generates the page.
 *
 */

void
v_clear_disp_list (short handle)
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
	
	VDI_TRAP_ESC (vdi_params, handle, 5,22, 0,0);
}
