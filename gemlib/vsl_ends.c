/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** changes the style of the line ends 
 *
 *  @param handle Device handle
 *  @param begstyle end style for the first point
 *  @param endstyle end style for the last point \n
 *         end style should be one of the following value:
 *         -  SQUARE (0)
 *         -  ARROWED (1)
 *         -  ROUND (2)
 *
 *  @since all VDI versions
 *
 */

void
vsl_ends (short handle, short begstyle, short endstyle)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_intin[2];   
	VDIPB vdi_params =               
	{                                
		&vdi_control[0],             /* vdi_control */
		&vdi_intin[0],               /* vdi_intin   */
		0L,                          /* vdi_ptsin   */
		0L,                          /* vdi_intout  */
		0L                           /* vdi_ptsout  */
	};
#endif
	
	vdi_intin[0] = begstyle;
	vdi_intin[1] = endstyle;

	VDI_TRAP (vdi_params, handle, 108, 0,2);
}
