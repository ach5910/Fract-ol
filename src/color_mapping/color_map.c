/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 02:18:58 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/01 02:19:00 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_color_map(t_maps *color_maps)
{
	color_maps[0] = &rainbow_squanch;
	color_maps[1] = &tree_map;
	color_maps[2] = &kryptonite;
	color_maps[3] = &dawn;
	color_maps[4] = &red_blue;
	color_maps[5] = &fire;
	color_maps[6] = &ice;
	color_maps[7] = &seashore;
	color_maps[8] = &kryptonite_center;
	color_maps[9] = &seashore_center;
	color_maps[10] = &fire_center;
	color_maps[11] = &dawn_center;
	color_maps[12] = &dawn;
	color_maps[13] = &dusk;
}

t_maps		get_color_map(int i)
{
	static t_maps *color_maps = NULL;

	if (color_maps == NULL)
	{
		color_maps = malloc(sizeof(t_maps) * 13);
		init_color_map(color_maps);
	}
	return (color_maps[(int)i]);
}

t_env	*set_color_map(t_env *e)
{
	static int col_iter = 0;
	t_maps map;

	map = get_color_map(col_iter % 13);
	e->color_map = map(0);
	e->c_iter = col_iter % 13 == 0 ? 4 : 1;
	col_iter++;
	return (e);
}
