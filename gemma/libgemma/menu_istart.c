/*
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

# include "extdef.h"

/* as of AES 3.30 (Falcon TOS) */

long
menu_istart(short flag, OBJECT *tree, short imenu, short item)
{
	GEM_ARRAY *gem_array = gem_control();

	gem_array->int_in[0] = flag;
	gem_array->int_in[1] = imenu;
	gem_array->int_in[2] = item;
	gem_array->addr_in[0] = (long)tree;

	return (long)call_aes(gem_array, 38);
}

/* EOF */
