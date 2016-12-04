/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:12:16 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/03 22:12:18 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_loop(t_env *e)
{
	//mlx_expose_hook(e->win, expose_hook, e);
	// mlx_key_hook(t_e->win, my_key_funct, t_e);
	mlx_hook(e->win, 2, 0, my_key_pressed, e);
	// mlx_hook(t_e->win, 5, 0, my_mouse_released, t_e);
	// mlx_hook(t_e->win, 6, 0, my_mouse_motion, t_e);
	// mlx_mouse_hook(t_e->win, my_mouse_function, t_e);
	mlx_loop_hook(e->mlx, my_loop_hook, e);
	mlx_loop(e->mlx);
}

int my_key_pressed(int keycode, t_env *e)
{
	
	if (keycode == 24)
		e->flags |= SCL;
	else if (keycode == 27)
		e->flags |= SCL | SIGN;
	else if (keycode == 123)
		e->flags |= TRAN_H;
	else if (keycode == 124)
		e->flags |= TRAN_H | SIGN;
	else if (keycode == 125)
		e->flags |= TRAN_V;
	else if (keycode == 126)
		e->flags |= TRAN_V | SIGN;
	return (0);
}

int my_loop_hook(t_env *e)
{
	if (e->flags & SIGN)
	{
		if (e->flags & SCL)
			e->zoom *= 0.8;
		else if (e->flags & TRAN_H)
			e->move_x -= 0.5;
		else if (e->flags & TRAN_V)
			e->move_y -= 0.5;
	}
	else
	{
		if (e->flags & SCL)
			e->zoom *= 1.25;
		else if (e->flags & TRAN_H)
			e->move_x += 0.5;
		else if (e->flags & TRAN_V)
			e->move_y += 0.5;
	}
	if (e->flags)
	{
		e->flags = 0;
		mlx_clear_window(e->mlx, e->win);
		draw(e);
	}
	return (0);
}
