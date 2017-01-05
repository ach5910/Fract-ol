/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:01:40 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 23:01:54 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(t_env *e, float a, float b)
{
	int		n;
	int		color;
	float	o_a;
	float	o_b;

	n = 0;
	a = 1.5 * (a - WIDTH / 2) / (WIDTH / 2);
	b = 1.5 * (b - HEIGHT / 2) / (HEIGHT / 2);
	while (n < e->max_iterations_j)
	{
		o_a = a;
		o_b = b;
		a = o_a * o_a - o_b * o_b + e->c_re;
		b = 2 * o_a * o_b + e->c_im;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	if (n == e->max_iterations_j)
		return (0);
	color = e->color_map[(int)((n * 64 * e->c_iter
		/ e->max_iterations_j)) % 64];
	return (color);
}

void	draw_j(t_env *e)
{
	float	i;
	float	j;
	int		p;
	int		color;

	j = 0;
	p = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			color = julia(e, i, j);
			p = (i * 4) + (j * e->img->size_line);
			e->img->data[p] = color & 0xFF;
			e->img->data[++p] = (color >> 8) & 0xFF;
			e->img->data[++p] = (color >> 16) & 0xFF;
			i++;
		}
		j++;
	}
	i = mlx_put_image_to_window(e->mlx, e->win, e->img->i_ptr, 0, 0);
	mlx_destroy_image(e->mlx, e->img->i_ptr);
	e->img->i_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
}
