/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractol_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:57:17 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 22:57:19 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*init_tripper(t_env *e)
{
	t_tree *t;
	t_vec2 *v;

	t = (t_tree*)malloc(sizeof(t_tree));
	t->init_len = 300;
	t->len = t->init_len;
	t->v = (t_vec2*)malloc(sizeof(t_vec2));
	t->v->x = W_T / 2;
	t->srt_ht = H_T * 7 / 8;
	t->v->y = H_T * 7 / 8;
	t->size = 13;
	t->branch = 13;
	t->theta = (4 * M_PI / 16);
	t->phi = (4 * M_PI / 16);
	t->rot = (M_PI / 2);
	t->scl = 0.7;
	t->delta_angle = (M_PI / 32);
	t->c_fmt = 0;
	t->code = "X";
	t->x_axiom = "F[+X][-X]";
	t->f_axiom = "F";
	e->t = t;
	return (e);
}

t_env	*init_windy(t_env *e)
{
	t_tree *t;
	t_vec2 *v;

	t = (t_tree*)malloc(sizeof(t_tree));
	t->init_len = 10;
	t->len = t->init_len;
	t->v = (t_vec2*)malloc(sizeof(t_vec2));
	t->v->x = W_T / 2;
	t->srt_ht = H_T * 15 / 16;
	t->v->y = H_T * 15 / 16;
	t->size = 5;
	t->branch = 5;
	t->theta = (M_PI / 8);
	t->phi = (M_PI / 8);
	t->rot = (M_PI / 2);
	t->scl = 0.85;
	t->delta_angle = (M_PI / 32);
	t->c_fmt = 0;
	t->code = "F";
	t->x_axiom = "X";
	t->f_axiom = "FF+[+F-F-F]-[-F+F+F]";
	e->t = t;
	return (e);
}

t_env	*init_ficus(t_env *e)
{
	t_tree *t;
	t_vec2 *v;

	t = (t_tree*)malloc(sizeof(t_tree));
	t->init_len = 4;
	t->len = t->init_len;
	t->v = (t_vec2*)malloc(sizeof(t_vec2));
	t->v->x = W_T / 2;
	t->srt_ht = H_T * 17 / 16;
	t->v->y = H_T * 17 / 16;
	t->size = 7;
	t->branch = 7;
	t->theta = (27.5 * M_PI / 180);
	t->phi = (27.5 * M_PI / 180);
	t->rot = (M_PI / 2);
	t->scl = 0.95;
	t->delta_angle = (M_PI / 32);
	t->c_fmt = 0;
	t->code = "X";
	t->x_axiom = "F[+X][-X]FX";
	t->f_axiom = "FF";
	e->t = t;
	return (e);
}

t_env	*init_tree(t_env *e, char *argv)
{
	e->win = mlx_new_window(e->mlx, W_T, H_T, "Fractal Tree");
	e->img = init_image_t(e);
	e = set_color_map(e);
	if (ft_str_index(argv, '1') == 4)
		e = init_tripper(e);
	if (ft_str_index(argv, '2') == 4)
		e = init_windy(e);
	if (ft_str_index(argv, '3') == 4)
		e = init_ficus(e);
	e->flags = 0;
	return (e);
}
