/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:08:39 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 23:08:51 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void tree_hook(t_env *e)
{
	mlx_mouse_hook(e->win, my_mouse_function_t, e);
	mlx_loop(e->mlx);
}

int my_mouse_function_t(int button, int i, int j, t_env *e)
{
	if (button == 5)
		e->t->theta += (M_PI / 32);
	else if (button == 4)
		e->t->theta -= (M_PI / 32);
	if (button == 6)
		e->t->phi += (M_PI / 32);
	else if (button == 7)
		e->t->phi -= (M_PI / 32);
	e->t->len = e->t->init_len;
	e->t->v->x = W_T / 2;
	e->t->v->y = e->t->srt_ht;
	mlx_clear_window(e->mlx, e->win);
	ft_draw_tree(e, e->t, e->t->code, 0);
	return (0);
}
