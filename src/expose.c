/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 05:04:19 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/05 05:04:39 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	expose_hook_j(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	draw_j(e);
	return (0);
}

int	expose_hook_m(t_env *e)
{
	mlx_clear_window(e->mlx, e->win_2);
	draw_m(e);
	return (0);
}

int	expose_hook_t(t_env *e)
{
	e->t->len = e->t->init_len;
	e->t->v->x = W_T / 2;
	e->t->v->y = e->t->srt_ht;
	mlx_clear_window(e->mlx, e->win);
	ft_draw_tree(e, e->t, e->t->code, 0);
	return (0);
}
