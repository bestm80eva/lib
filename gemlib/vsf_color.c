/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** sets the color index for filled areas
 *
 *  @param handle Device handle
 *  @param index requested fill color. If the index is invalid, color 
 *         index 1 will be selected. If you use a colored pattern (see vsf_udpat()) the 
 *         color index will be ignored; you should set it to 1.
 *
 *  @return realized color
 *
 *  @since all VDI versions
 *
 */

short
vsf_color (short handle, short index)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_intout[1]; 
	VDIPB vdi_params =               
	{                                
		&vdi_control[0],             /* vdi_control */
		&index,                      /* vdi_intin   */
		0L,                          /* vdi_ptsin   */
		&vdi_intout[0],              /* vdi_intout  */
		0L                           /* vdi_ptsout  */
	};
#else
	vdi_intin[0] = index;
#endif
	
	VDI_TRAP (vdi_params, handle, 25, 0,1);

	return vdi_intout[0];
}
