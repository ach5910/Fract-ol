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
# define HEIGHT 640
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
	t_img	*img;
	double	zoom;
	double	move_x;
	double	move_y;
	unsigned char flags;

}				t_env;

int main(void);
int mandlebrot(t_env *e, float r);
t_img *init_image(t_env *e);
t_env *init_environment(void);
void	my_loop(t_env *e);
void	draw(t_env *e);
int my_loop_hook(t_env *e);
int my_key_pressed(int keycode, t_env *e);

#endif
