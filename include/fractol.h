/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:49:39 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/03 20:49:42 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "math.h"
# define WIDTH 800
# define HEIGHT 600
# define W_2 500
# define H_2 500
# define TRAN_H 0x01
# define TRAN_V  0x02
# define SCL  0x04
# define SIGN 0x08
# define JULIA 0x01
# define MAND  0x02
# define TREE  0x04

typedef struct 	s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct  s_img
{
	void	*i_ptr;
	int bpp;
	int size_line;
	int endian;
	char *data;
	int w;
	int h;
}				t_img;

typedef struct 	s_env
{
	void	*mlx;
	void	*win;
	void	*win_2;
	t_img	*img;
	t_img	*img_2;
	double	zoom;
	double	move_x;
	double	move_y;
	int		loc_x;
	int		loc_y;
	unsigned char fractol;
	unsigned char flags;
	int max_iterations;
	int max_iterations_j;

}				t_env;

// int count = 0;
int main(int argc, char **argv);
int mandlebrot(t_env *e, float r, float c_a, float c_b);
int julia(t_env *e, float c_a, float c_b, float c_re, float c_im);
t_img *init_image(t_env *e);
t_env	*init_julia(t_env *e);
t_env	*init_mandlebrot(t_env *e);
t_env	*init_tree(t_env *e);
t_env *init_environment(char *argv);
void	my_loop(t_env *e);
void	draw(t_env *e);
void	draw_j(t_env *e, float c_re, float c_im);
void	julia_hook(t_env *e);
void	mandlebrot_hook(t_env *e);
// void	tree_hook(t_env *e);
int my_loop_hook_j(t_env *e);
int my_key_pressed_j(int keycode, t_env *e);
int my_mouse_function_j(int keycode, int i, int h, t_env *e);
int my_mouse_motion_j(int i , int j , t_env *e);
int my_loop_hook_m(t_env *e);
int my_key_pressed_m(int keycode, t_env *e);
int my_mouse_function_m(int keycode, int i, int h, t_env *e);
int my_mouse_motion_m(int i , int j , t_env *e);
#endif
