/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dusk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 03:38:05 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/01 03:38:17 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*dusk(int i)
{
	static int ary[64] = {
	0xffffff, 0xfff7ff, 0xffefff, 0xffe7ff,
	0xffdfff, 0xffd7ff, 0xffcfff, 0xffc7ff,
	0xffbfff, 0xffb7ff, 0xffafff, 0xffa8ff,
	0xffa0ff, 0xff98ff, 0xff90ff, 0xff88ff,
	0xff80ff, 0xf778ff, 0xee70ff, 0xe768ff,
	0xdf60ff, 0xd758ff, 0xcf4fff, 0xc747ff,
	0xbf3fff, 0xb737ff, 0xaf2fff, 0xa727ff,
	0x9f1fff, 0x9717ff, 0x8f0fff, 0x8607ff,
	0x7e00fe, 0x7600f6, 0x6f00ee, 0x6600e6,
	0x5e00df, 0x5700d7, 0x4f00cf, 0x4600c7,
	0x3f00bf, 0x3600b7, 0x2f00af, 0x2700a8,
	0x1f00a0, 0x160098, 0xe0090, 0x60088,
	0x80, 0x78, 0x70, 0x68,
	0x60, 0x58, 0x4f, 0x47,
	0x3f, 0x37, 0x2f, 0x27,
	0x1f, 0x16, 0xe, 0x6};

	return (ary);
}