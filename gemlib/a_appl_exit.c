/*
 *  $Id$
 */

#include "gem_aesP.h"

/** should be called at the termination of any program initialized
 *  with appl_init().
 *
 *  @param global_aes global AES array
 *
 *  @return 0 if an error occurred or non-zero otherwise.
 *
 *  @since All AES versions.
 *
 *  @sa mt_appl_init()
 *
 *  The proper procedure for handling an error from this
 *  function is currently undefined.
 *
 */

short 
mt_appl_exit(short *global_aes)
{
	AES_PARAMS(19,0,1,0,0);
                    
	AES_TRAP(aes_params);

	return aes_intout[0];
}

#ifdef appl_exit
#undef appl_exit
#endif
short 
appl_exit(void)
{
	return(mt_appl_exit(aes_global));
}
