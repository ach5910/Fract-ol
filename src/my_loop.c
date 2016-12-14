/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:12:16 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/06 14:44:51 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_loop(t_env *e)
{
	//mlx_expose_hook(e->win, expose_hook, e);
	// mlx_key_hook(t_e->win, my_key_funct, t_e);
	mlx_hook(e->win, 2, 0, my_key_pressed, e);
	// mlx_hook(t_e->win, 5, 0, my_mouse_released, t_e);
	mlx_hook(e->win, 6, 0, my_mouse_motion, e);
	mlx_mouse_hook(e->win, my_mouse_function,e);
	mlx_loop_hook(e->mlx, my_loop_hook, e);
	mlx_loop(e->mlx);
}

int my_key_pressed(int keycode, t_env *e)
{
	
	if (keycode == 24)
		e->flags |= SCL ;
	else if (keycode == 27)
		e->flags |= SCL | SIGN;
	else if (keycode == 123)
		e->flags |= TRAN_H | SIGN;
	else if (keycode == 124)
		e->flags |= TRAN_H;
	else if (keycode == 125)
		e->flags |= TRAN_V;
	else if (keycode == 126)
		e->flags |= TRAN_V | SIGN;
	else if (keycode == 48)
		e->scale *= 0.5; 
	return (0);
}

int my_mouse_function(int button, int i, int j, t_env *e)
{
	 
	if (button == 1)
		e->max_iterations += 5;
	else if (button == 2)
		e->max_iterations -= 5;;
	if (button == 1 || button == 2)
	{
		mlx_clear_window(e->mlx, e->win);
		draw_j(e, 0, 0);
	}
	return (0);
}

int my_mouse_motion(int i , int j , t_env *e)
{
	// t_tree *t;
	// t_vec2 *v;
	// ft_printf("X = %d Y = %d\n", i , j);
	if (i > 0 && i < WIDTH && j > 0 && j < HEIGHT)
	{
		mlx_clear_window(e->mlx, e->win);
		draw_j(e, 2.5 * (i - WIDTH / 2) / (WIDTH / 2 * e->zoom) + e->move_x ,
			2.5 * (j - HEIGHT / 2) / (HEIGHT / 2 * e->zoom) + e->move_y);
	}
	return (0);
}

int my_loop_hook(t_env *e)
{
	if (e->flags & SIGN)
	{
		if (e->flags & SCL)
			e->zoom /= 1.08;
		else if (e->flags & TRAN_H)
			e->move_x -= 0.08 / e->zoom;
		else if (e->flags & TRAN_V)
			e->move_y -= 0.08 / e->zoom;
	}
	else
	{
		if (e->flags & SCL)
			e->zoom *= 1.08;
		else if (e->flags & TRAN_H)
			e->move_x += 0.08 / e->zoom;
		else if (e->flags & TRAN_V)
			e->move_y += 0.08 / e->zoom;
	}
	if (e->flags)
	{
		e->flags = 0;
		mlx_clear_window(e->mlx, e->win);
		draw_j(e, 0, 0);
	}
	return (0);
}
