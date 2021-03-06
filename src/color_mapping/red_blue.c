/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_blue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 03:39:34 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/01 03:39:44 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*red_blue(int i)
{
	static int ary[64] = {
	0x5f0000, 0x650000, 0x6b0000, 0x720000,
	0x780000, 0x7e0000, 0x840000, 0x8a0000,
	0x900000, 0x960000, 0x9d0000, 0xa30000,
	0xa90000, 0xaf0000, 0xb50000, 0xbb0000,
	0xc10101, 0xc51111, 0xc92121, 0xcd3131,
	0xd14141, 0xd55151, 0xd96161, 0xdd7171,
	0xe08181, 0xe49191, 0xe8a1a1, 0xecb1b1,
	0xf0c1c1, 0xf4d1d1, 0xf8e1e1, 0xfcf1f1,
	0xfdfdff, 0xededfb, 0xddddf7, 0xcdcdf3,
	0xbdbdef, 0xadadec, 0x9d9de8, 0x8d8de4,
	0x7d7de0, 0x6d6ddc, 0x5d5dd9, 0x4d4dd5,
	0x3d3dd1, 0x2d2dcd, 0x1d1dca, 0xd0dc6,
	0xc2, 0xbb, 0xb5, 0xaf,
	0xa9, 0xa2, 0x9c, 0x96,
	0x90, 0x89, 0x83, 0x7d,
	0x77, 0x70, 0x6a, 0x64};

	return (ary);
}
