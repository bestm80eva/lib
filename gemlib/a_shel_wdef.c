/*
 *  $Id$
 */

#include "gem_aesP.h"

/** 
 *
 *  @param lpcmd
 *  @param lpdir
 *  @param global_aes global AES array
 *
 *  @return 
 *
 *  @since 
 *
 *  @sa 
 *
 */

short 
mt_shel_wdef(const char *lpcmd, const char *lpdir, short *global_aes)
{
	AES_PARAMS(127,0,1,2,0);
   
	aes_addrin[0] = (long)lpcmd;
	aes_addrin[1] = (long)lpdir;

	AES_TRAP(aes_params);

	return aes_intout[0];
}
