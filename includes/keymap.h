/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 23:54:35 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/18 17:55:18 by jeffersoncity    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

/*
*************************** LINUX & Mac OS X keymap **************************
*/

# ifdef __linux__
#  define KEY_ESC		0xFF1B
#  define KEY_LEFT		0xFF51
#  define KEY_UP		0xFF52
#  define KEY_RIGHT		0xFF53
#  define KEY_DOWN		0xFF54
#  define KEY_PLUS		0xFFAB
#  define KEY_MINUS		0xFFAD
#  define KEY_DIV		0xFFAF
#  define KEY_MUL		0xFFAA
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
#  define KEY_ESC		53
#  define KEY_LEFT		123
#  define KEY_UP		126
#  define KEY_RIGHT		124
#  define KEY_DOWN		125
#  define KEY_PLUS		69
#  define KEY_MINUS		78
#  define KEY_DIV		75
#  define KEY_MUL		67
#  define KEY_Q			12
#  define KEY_E			14
#  define KEY_NUM8		91
#  define KEY_NUM2		84
#  define KEY_NUM4		86
#  define KEY_NUM6		88
#  define KEY_NUM5		87
#  define KEY_NUM0		82
#  define KEY_PGUP		116
#  define KEY_PGDOWN	121
#  define KEY_1			18
#  define KEY_2			19
#  define KEY_3			20
#  define KEY_B_O		33
#  define KEY_B_C		30
# endif

#endif
