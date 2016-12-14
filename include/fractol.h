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
# define WIDTH 1500
# define HEIGHT 1000
# define W_2 800
# define H_2 800
# define TRAN_H 0x01
# define TRAN_V  0x02
# define SCL  0x04
# define SIGN 0x08

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
	double  scale;
	unsigned char flags;
	int max_iterations;
	int max_iterations_j;

}				t_env;

// int count = 0;
int main(void);
int mandlebrot(t_env *e, float r, float c_a, float c_b);
int julia(t_env *e, float c_a, float c_b, float c_re, float c_im);
t_img *init_image(t_env *e);
t_env *init_environment(void);
void	my_loop(t_env *e);
void	draw(t_env *e);
void	draw_j(t_env *e, float c_re, float c_im);
int my_loop_hook(t_env *e);
int my_key_pressed(int keycode, t_env *e);
int my_mouse_function(int keycode, int i, int h, t_env *e);
int my_mouse_motion(int i , int j , t_env *e);

#endif
