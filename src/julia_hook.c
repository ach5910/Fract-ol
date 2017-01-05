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
	mlx_hook(e->win_2, 2, 0, my_key_pressed_j, e);
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
	else if (keycode == 49)
		e->flags |= C_MAP;
	else if (keycode == 258)
		e->flags ^= FREEZE;
	return (0);
}

int my_mouse_function_j(int button, int i, int j, t_env *e)
{
	static int d = 0;
	double y;
	double x;

	e->loc_x = i;
	e->loc_y = j;
	if (button == 4)
		e->flags |= SCL | SIGN;
	else if (button == 5)
		e->flags |= SCL;
	if (e->flags & FREEZE)
		return (0);
	if (button == 1)
		e->max_iterations_j += 2;
	else if (button == 2)
		e->max_iterations_j -= 2;
	if (button == 1 || button == 2)
	{
		mlx_clear_window(e->mlx, e->win);
		e->c_re = (i - W_2 / 2) / (W_2 / 2 * e->zoom) + e->move_x;
		e->c_im = (j - H_2 / 2) / (H_2 / 2 * e->zoom) + e->move_y;
		draw_j(e);
	}
	return (0);
}

int my_mouse_motion_j(int i , int j , t_env *e)
{
	if (e->flags & FREEZE)
		return (0);
	if (i > 0 && i < W_2 && j > 0 && j < H_2)
	{
		mlx_clear_window(e->mlx, e->win);
		e->c_re = (i - W_2 / 2) / (W_2 / 2 * e->zoom) + e->move_x;
		e->c_im = (j - H_2 / 2) / (H_2 / 2 * e->zoom) + e->move_y;
		draw_j(e);
	}
	return (0);
}

int my_loop_hook_j(t_env *e)
{
	if (e->flags & SIGN)
		e->zoom /= 1.085;
	else if (e->flags & SCL)
		e->zoom *= 1.085;
	if (e->flags & SCL)
	{
		e->flags &= FREEZE;
		e->move_x += (e->loc_x - W_2 / 2) / (W_2 / 2 * e->zoom) / 8;
		e->move_y += (e->loc_y - H_2 / 2) / (H_2 / 2 * e->zoom) / 8;
		mlx_clear_window(e->mlx, e->win_2);
		draw_m(e);
	}
	if (e->flags & FREEZE)
		return (0);
	else if (e->flags & C_MAP)
	{
		e->flags = 0;
		e = set_color_map(e);
		mlx_clear_window(e->mlx, e->win_2);
		draw_m(e);
		mlx_clear_window(e->mlx, e->win);
		e->c_re = (W_2 / 2) / (W_2 / 2 * e->zoom) + e->move_x;
		e->c_im = (H_2 / 2) / (H_2 / 2 * e->zoom) + e->move_y;
		draw_j(e);
	}
	return (0);
}