/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:54:03 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 22:54:05 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*init_environment(char *argv)
{
	t_env *e;
	unsigned char fract;

	if (!(fract = parse_input(argv)))
		return (NULL);
	e = (t_env*)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	mlx_do_key_autorepeatoff(e->mlx);
	if (fract & JULIA)
		e = init_julia(e);
	else if (fract & MAND)
		e = init_mandlebrot(e);
	else if (fract & TREE)
		e = init_tree(e, argv);
	e->fractol |= fract;
	return (e);
}

t_env	*init_julia(t_env *e)
{
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fract'ol - Julia");
	e->win_2 = mlx_new_window(e->mlx, W_2, H_2, "Mandelbrot Explorer");
	e->img_2 = init_image_2(e);
	e->img = init_image(e);
	e->zoom = 1;
	e->move_x = 0;
	e->move_y = 0;
	e->loc_x = 0;
	e->loc_y = 0;
	e->flags = 0;
	e->max_iterations = 40;
	e->max_iterations_j = 50;
	return (e);
}

t_env	*init_mandlebrot(t_env *e)
{
	e->win_2 = mlx_new_window(e->mlx, W_2, H_2, "Fract'ol - Mandelbrot");
	e->img_2 = init_image_2(e);
	e->zoom = 1;
	e->move_x = 0;
	e->move_y = 0;
	e->loc_x = 0;
	e->loc_y = 0;
	e->flags = 0;
	e->max_iterations = 50;
	return (e);
}
