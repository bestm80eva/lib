/*
 *  $Id$
 */

#include "gem_aesP.h"

/** allows the user to change the size of
 *  a box outline with a fixed starting point.
 *
 *  @param bx x-coordinate of the fixed upper-left corner of the box to
 *         stretch or shrink.
 *  @param by y-coordinate of the fixed upper-left corner of the box to
 *         stretch or shrink.
 *  @param mw minimum width that the rectangle can be shrunk to.
 *  @param mh minimum height that the rectangle can be shrunk to.
 *  @param rw pointer to a short integer which will be filled in
 *         with the ending width of the box when the mouse
 *         button is released. \n
 *         [option CHECK_NULLPTR] \a rw may be NULL
 *  @param rh pointer to a short integer which will be filled in
 *         with the ending height of the box when the mouse
 *         button is released. \n
 *         [option CHECK_NULLPTR] \a rh may be NULL
 *  @param global_aes global AES array
 *
 *  @return 0 if an error occurred or non-zero otherwise.
 *
 *  @since All AES versions.
 *
 *  @sa mt_graf_dragbox(), mt_graf_slidebox()
 *
 *  This function should only be entered when the user has
 *  depressed the mouse button as it returns when the mouse
 *  button is released.
 *
 *  @note There is currently no defined method of handling an error
 *        generated by this function.
 *
 */

short
mt_graf_rubberbox(short bx, short by, short mw, short mh, short *rw, short *rh, short *global_aes)
{
	AES_PARAMS(70,4,3,0,0);

	aes_intin[0] = bx;
	aes_intin[1] = by;
	aes_intin[2] = mw;
	aes_intin[3] = mh;

	AES_TRAP(aes_params);

#if CHECK_NULLPTR
	if (rw)
#endif
	*rw = aes_intout[1];
#if CHECK_NULLPTR
	if (rh)
#endif
	*rh = aes_intout[2];

	return aes_intout[0];
}
