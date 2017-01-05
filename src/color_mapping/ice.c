/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 03:41:11 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/01 03:41:23 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*ice(int i)
{
	static int ary[64] = {
	0xffffff, 0xf7ffff, 0xefffff, 0xe7ffff,
	0xdfffff, 0xd7ffff, 0xcfffff, 0xc7ffff,
	0xbfffff, 0xb7ffff, 0xafffff, 0xa8ffff,
	0xa0ffff, 0x98ffff, 0x90ffff, 0x88ffff,
	0x80ffff, 0x78f7ff, 0x70eeff, 0x68e7ff,
	0x60dfff, 0x58d7ff, 0x4fcfff, 0x47c7ff,
	0x3fbfff, 0x37b7ff, 0x2fafff, 0x27a7ff,
	0x1f9fff, 0x1797ff, 0xf8fff, 0x786ff,
	0x7efe, 0x76f6, 0x6fee, 0x66e6,
	0x5edf, 0x57d7, 0x4fcf, 0x46c7,
	0x3fbf, 0x36b7, 0x2faf, 0x27a8,
	0x1fa0, 0x1698, 0xe90, 0x688,
	0x80, 0x78, 0x70, 0x68,
	0x60, 0x58, 0x4f, 0x47,
	0x3f, 0x37, 0x2f, 0x27,
	0x1f, 0x16, 0xe, 0x6};

	return (ary);
}
