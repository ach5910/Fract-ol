/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:05:37 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 23:05:47 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia_hook(t_env *e)
{
	//mlx_expose_hook(e->win, expose_hook, e);
	// mlx_key_hook(t_e->win, my_key_funct, t_e);
	mlx_hook(e->win_2, 2, 0, my_key_pressed_j, e);
	// mlx_hook(e->win_2, 5, 0, my_mouse_released, e);
	mlx_hook(e->win_2, 6, 0, my_mouse_motion_j, e);
	mlx_mouse_hook(e->win_2, my_mouse_function_j,e);
	mlx_loop_hook(e->mlx, my_loop_hook_j, e);
	mlx_loop(e->mlx);
}

int my_key_pressed_j(int keycode, t_env *e)
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
	// else if (keycode == 48)
	// 	e->scale *= 0.5; 
	return (0);
}

int my_mouse_function_j(int button, int i, int j, t_env *e)
{
	static int d = 0;
	double y;
	double x;

	e->loc_x = i;
	e->loc_y = j;
	x = e->move_x;
	if (button == 1)
		e->max_iterations_j += 2;
	else if (button == 2)
		e->max_iterations_j -= 2;
	else if (button == 4)
	{
		
		// e->move_x += (i - W_2 / 2) / e->zoom;
		// e->move_y += (j - H_2 / 2) / e->zoom;
		// e->zoom /= 1.085;
		// e->move_x += (i - W_2 / 2) / (W_2 / 2 * e->zoom) / 8;
		// e->move_y += (j - H_2 / 2) / (H_2 / 2 * e->zoom) / 8;
		e->flags |= SCL | SIGN;
		// if (d % 2)
		// 	e->flags |= SCL;
		// d++;
	}
	else if (button == 5)
	{
		
		// e->move_x += (i - W_2 / 2) / e->zoom;
		// e->move_y += (j - H_2 / 2) / e->zoom;
		// e->zoom *= 1.085;
		// e->move_x += (i - W_2 / 2) / (W_2 / 2 * e->zoom) / 8;
		// e->move_y += (j - H_2 / 2) / (H_2 / 2 * e->zoom) / 8;
		e->flags |= SCL;
		// if (d % 2)
		// 	e->flags |= SCL;
		// d++;
	}
	if (button == 1 || button == 2)
	{
		mlx_clear_window(e->mlx, e->win);
		draw_j(e, (i - W_2 / 2) / (W_2 / 2 * e->zoom) + e->move_x ,
			(j - H_2 / 2) / (H_2 / 2 * e->zoom) + e->move_y);
	}
	return (0);
}

int my_mouse_motion_j(int i , int j , t_env *e)
{
	// t_tree *t;
	// t_vec2 *v;
	// ft_printf("X = %d Y = %d\n", i , j);
	if (i > 0 && i < W_2 && j > 0 && j < H_2)
	{
		mlx_clear_window(e->mlx, e->win);
		draw_j(e, (i - W_2 / 2) / (W_2 / 2 * e->zoom) + e->move_x ,
			(j - H_2 / 2) / (H_2 / 2 * e->zoom) + e->move_y);
	}
	return (0);
}

int my_loop_hook_j(t_env *e)
{
	if (e->flags & SIGN)
	{
		// if (e->flags & SCL)
		e->zoom /= 1.085;
		// else if (e->flags & TRAN_H)
		// 	e->move_x -= 0.08 / e->zoom;
		// else if (e->flags & TRAN_V)
		// 	e->move_y -= 0.08 / e->zoom;
	}
	else if (e->flags & SCL)
	{
		// if (e->flags & SCL)
		e->zoom *= 1.085;
		// else if (e->flags & TRAN_H)
		// 	e->move_x += 0.08 / e->zoom;
		// else if (e->flags & TRAN_V)
		// 	e->move_y += 0.08 / e->zoom;
	}
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