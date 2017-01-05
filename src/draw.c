/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:57:33 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/01 00:57:34 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_tree	*draw_branch(t_env *e, t_tree *t)
{
	t_vec2	*p1;
	t_vec2	*p2;
	int		center;

	center = (int)sqrt(pow(W_T / 2, 2) + pow(H_T / 2, 2));
	p1 = t->v;
	p2 = (t_vec2*)malloc(sizeof(t_vec2));
	p2->x = p1->x - t->len * cos(t->rot);
	p2->y = p1->y - t->len * sin(t->rot);
	if (fabs(p1->y - p2->y) > fabs(p1->x - p2->x))
		draw_lines_y(e, p1, p2, center);
	else
		draw_lines_x(e, p1, p2, center);
	t->v = p2;
	return (t);
}

t_line	*get_line_params_x(t_env *e, t_vec2 *p1, t_vec2 *p2)
{
	t_line	*data;

	data = (t_line*)malloc(sizeof(t_line));
	data->dx = fabs(p1->x - p2->x);
	data->dy = fabs(p1->y - p2->y);
	data->p = (2 * data->dy) - data->dx;
	data->end = p2->x > p1->x ? p2 : p1;
	data->start = p2->x > p1->x ? p1 : p2;
	data->i = data->start->x;
	data->j = data->start->y;
	data->j_incr = data->end->y > data->start->y ? 1 : -1;
	return (data);
}

void	draw_lines_x(t_env *e, t_vec2 *p1, t_vec2 *p2, int center)
{
	t_line	*d;
	int		color;

	d = get_line_params_x(e, p1, p2);
	while (d->i < d->end->x)
	{
		color = get_color(e, d->i, d->j, center);
		mlx_pixel_put(e->mlx, e->win, d->i, d->j, color);
		if (d->p < 0)
			d->p += (2 * d->dy);
		else
		{
			d->p += (2 * d->dy) - (2 * d->dx);
			d->j += d->j_incr;
		}
		d->i++;
	}
	ft_memdel((void **)&d);
}

t_line	*get_line_params_y(t_env *e, t_vec2 *p1, t_vec2 *p2)
{
	t_line	*data;

	data = (t_line*)malloc(sizeof(t_line));
	data->dx = fabs(p1->x - p2->x);
	data->dy = fabs(p1->y - p2->y);
	data->p = (2 * data->dx) - data->dy;
	data->end = p2->y > p1->y ? p2 : p1;
	data->start = p2->y > p1->y ? p1 : p2;
	data->i = data->start->y;
	data->j = data->start->x;
	data->j_incr = data->end->x > data->start->x ? 1 : -1;
	return (data);
}

void	draw_lines_y(t_env *e, t_vec2 *p1, t_vec2 *p2, int center)
{
	t_line	*d;
	int		color;

	d = get_line_params_y(e, p1, p2);
	color = get_color(e, d->j, d->i, center);
	mlx_pixel_put(e->mlx, e->win, d->j, d->i, color);
	while (d->i < d->end->y)
	{
		color = get_color(e, d->j, d->i, center);
		mlx_pixel_put(e->mlx, e->win, d->j, d->i, color);
		if (d->p < 0)
			d->p += (2 * d->dx);
		else
		{
			d->p += (2 * d->dx) - (2 * d->dy);
			d->j += d->j_incr;
		}
		d->i++;
	}
	ft_memdel((void **)&d);
}
