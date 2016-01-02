

#include "gem_vdiP.h"
#include "mt_gemx.h"

/** see v_ftext_offset()
 *
 *  @param handle Device handle
 *  @param x 
 *  @param y 
 *  @param wstr 
 *  @param num string len
 *  @param offset 
 *
 *
 */

typedef struct
{
    short    vdi_control[VDI_CNTRLMAX];
    short    vdi_intin[VDI_INTINMAX];
    short    vdi_intout[VDI_INTOUTMAX];
    short    vdi_ptsin[VDI_PTSINMAX];
    short    vdi_ptsout[VDI_PTSOUTMAX];
} VDIPARBLK;

extern VDIPARBLK _VDIParBlk;

void
udef_v_ftext_offset16n (short handle, short x, short y,
                  const WCHAR * wstr, short num, const short * offset)
{
	const long * src = (const long*)offset;
	long       * dst =       (long*)_VDIParBlk.vdi_ptsin;
	short     i;
	
	VDI_PARAMS(_VDIParBlk.vdi_control, (const short *)wstr, _VDIParBlk.vdi_ptsin, vdi_dummy, vdi_dummy);
	if(num>VDI_PTSINMAX) num=VDI_PTSINMAX;
	
	
	_VDIParBlk.vdi_ptsin[0] = x;
	_VDIParBlk.vdi_ptsin[1] = y;
	for (i = 0; i < num; i++) {
		*(++dst) = *(src++);
	}

	VDI_TRAP (vdi_params, handle, 241, (num +1),num);
}
