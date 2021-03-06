/*
 *  $Id$
 */
 
#include "gem_vdiP.h"
#include "mt_gemx.h"

/** see v_ftext_offset()
 *
 *  @param handle Device handle
 *  @param x 
 *  @param y 
 *  @param wstr 
 *  @param offset 
 *
 *
 */

void
v_ftext_offset16 (short handle, short x, short y,
                  const WCHAR * wstr, const short * offset)
{
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_ptsin[VDI_PTSINMAX*2+2];   
	const long * src = (const long*)offset;
	long       * dst =       (long*)vdi_ptsin;
	short     i, len = vdi_wstrlen ((const short *)wstr);

	VDI_PARAMS(vdi_control, (const short *)wstr, vdi_ptsin, vdi_dummy, vdi_dummy);
	if(len>VDI_PTSINMAX) len=VDI_PTSINMAX;
	
	
	vdi_ptsin[0] = x;
	vdi_ptsin[1] = y;
	for (i = 0; i < len; i++) {
		*(++dst) = *(src++);
	}

	VDI_TRAP (vdi_params, handle, 241, (len +1),len);
}
