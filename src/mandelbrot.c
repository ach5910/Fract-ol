/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:00:39 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 23:00:42 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_env *e, float c_a, float c_b)
{
	int		n;
	float	a;
	float	o_a;
	float	b;
	float	o_b;

	n = 0;
	a = 0;
	b = 0;
	while (n < e->max_iterations)
	{
		o_a = a * a - b * b;
		o_b = 2 * a * b;
		a = o_a + c_a;
		b = o_b + c_b;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	if (n == e->max_iterations)
		return (0);
	return (e->color_map[(int)(n * 64 * e->c_iter / e->max_iterations) % 64]);
}

void	pixel_to_img(t_env *e, int i, int j, int color)
{
	int p;

	p = (i * 4) + (j * e->img_2->size_line);
	e->img_2->data[p] = color & 0xFF;
	e->img_2->data[++p] = (color >> 8) & 0xFF;
	e->img_2->data[++p] = (color >> 16) & 0xFF;
}

void	draw_m(t_env *e)
{
	int		i;
	int		j;
	float	c_a;
	float	c_b;
	int		color;

	j = 0;
	while (j < H_2)
	{
		i = 0;
		while (i < W_2)
		{
			c_a = (i - W_2 / 2) / (W_2 / 2 * e->zoom) + e->move_x;
			c_b = (j - H_2 / 2) / (H_2 / 2 * e->zoom) + e->move_y;
			color = mandelbrot(e, c_a, c_b);
			pixel_to_img(e, i, j, color);
			i++;
		}
		j++;
	}
	i = mlx_put_image_to_window(e->mlx, e->win_2, e->img_2->i_ptr, 0, 0);
	mlx_destroy_image(e->mlx, e->img_2->i_ptr);
	e->img_2->i_ptr = mlx_new_image(e->mlx, W_2, H_2);
}
