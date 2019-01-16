/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 23:54:35 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 20:27:00 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

/*
** TODO: Change MAC OS X keymappings
*/

# ifdef __linux__
#  define KEY_ESC		0xFF1B
#  define KEY_LEFT		0xFF51
#  define KEY_UP		0xFF52
#  define KEY_RIGHT		0xFF53
#  define KEY_DOWN		0xFF54
#  define KEY_PLUS		0xFFAB
#  define KEY_MINUS		0xFFAD
#  define KEY_Q			0x71
#  define KEY_E			0x65
#  define KEY_NUM8		0xFF97
#  define KEY_NUM2		0xFF99
#  define KEY_NUM4		0xFF96
#  define KEY_NUM6		0xFF98
#  define KEY_NUM5		0xFF9D
#  define KEY_NUM0		0xFF9E
#  define KEY_PGUP		0xFF55
#  define KEY_PGDOWN	0xFF56
#  define KEY_1			0x31
#  define KEY_2			0x32
#  define KEY_3			0x33
#  define KEY_B_O		0x5B
#  define KEY_B_C		0x5D
# else
#  define KEY_ESC		0xFF1B
#  define KEY_LEFT		0xFF51
#  define KEY_UP		0xFF52
#  define KEY_RIGHT		0xFF53
#  define KEY_DOWN		0xFF54
#  define KEY_PLUS		0xFFAB
#  define KEY_MINUS		0xFFAD
#  define KEY_Q			0x71
#  define KEY_E			0x65
#  define KEY_NUM8		0xFF97
#  define KEY_NUM2		0xFF99
#  define KEY_NUM4		0xFF96
#  define KEY_NUM6		0xFF98
#  define KEY_NUM5		0xFF9D
#  define KEY_NUM0		0xFF9E
#  define KEY_PGUP		0xFF55
#  define KEY_PGDOWN	0xFF56
#  define KEY_1			0x31
#  define KEY_2			0x32
#  define KEY_3			0x33
#  define KEY_B_O		0x5B
#  define KEY_B_C		0x5D
# endif

#endif
