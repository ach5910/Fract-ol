/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:06:46 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 23:06:58 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandlebrot_hook(t_env *e)
{
	//mlx_expose_hook(e->win, expose_hook, e);
	// mlx_key_hook(t_e->win, my_key_funct, t_e);
	mlx_hook(e->win_2, 2, 0, my_key_pressed_m, e);
	// mlx_hook(e->win_2, 5, 0, my_mouse_released, e);
	mlx_mouse_hook(e->win_2, my_mouse_function_m, e);
	mlx_loop_hook(e->mlx, my_loop_hook_m, e);
	mlx_loop(e->mlx);
}

int my_key_pressed_m(int keycode, t_env *e)
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
	return (0);
}

int my_mouse_function_m(int button, int i, int j, t_env *e)
{
	e->loc_x = i;
	e->loc_y = j;
	if (button == 1)
		e->max_iterations += 2;
	else if (button == 2)
		e->max_iterations -= 2;
	else if (button == 4)
		e->flags |= SCL | SIGN;
	else if (button == 5)
		e->flags |= SCL;
	if (button == 1 || button == 2)
	{
		mlx_clear_window(e->mlx, e->win_2);
		draw_m(e);
	}
	return (0);
}


int my_loop_hook_m(t_env *e)
{
	if (e->flags & SIGN)
		e->zoom /= 1.085;
	else if (e->flags & SCL)
		e->zoom *= 1.085;
	if (e->flags & SCL)
	{
		e->flags = 0;
		e->move_x += (e->loc_x - W_2 / 2) / (W_2 / 2 * e->zoom) / 8;
		e->move_y += (e->loc_y - H_2 / 2) / (H_2 / 2 * e->zoom) / 8;
		mlx_clear_window(e->mlx, e->win_2);
		draw_m(e);
	}
	return (0);
}