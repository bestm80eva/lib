/*
 *  $Id$
 */

#include "gem_vdiP.h"

/** allows you to save application specific opcodes in a 
 *  metafile. Opcodes 0 to 100 are reserved, the range above it can be used.
 *
 *  @param handle Device handle
 *  @param numvdi_intin 
 *  @param avdi_intin 
 *  @param num_ptsin 
 *  @param a_ptsin 
 *
 *  @since all VDI versions
 *
 *  The opcode is stored in a_intin[0].
 *
 */

void
v_write_meta (short handle, short numvdi_intin, short *avdi_intin,
              short num_ptsin, short *a_ptsin)
{
#if USE_LOCAL_VDIPB
	short vdi_control[VDI_CNTRLMAX]; 
	VDIPB vdi_params =               
	{                                
		&vdi_control[0],             /* vdi_control */
		avdi_intin,                  /* vdi_intin   */
		a_ptsin,                     /* vdi_ptsin   */
		0L,                          /* vdi_intout  */
		0L                           /* vdi_ptsout  */
	};
#else
	vdi_params.intin = avdi_intin;
	vdi_params.ptsin = a_ptsin;
#endif
	
	VDI_TRAP_ESC (vdi_params, handle, 5,99, num_ptsin,numvdi_intin);

#if !(USE_LOCAL_VDIPB)
	vdi_params.intin = vdi_intin;
	vdi_params.ptsin = vdi_ptsin;
#endif
}
