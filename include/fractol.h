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
# define W_2 800
# define H_2 600
# define W_T 1500
# define H_T 1000
# define TRAN_H 0x01
# define TRAN_V  0x02
# define SCL  0x04
# define SIGN 0x08
# define C_MAP 0X10
# define FREEZE 0x20
# define JULIA 0x01
# define MAND  0x02
# define TREE  0x04
# define COLOR 0x01

typedef int	*(*t_maps)(int);

typedef struct 	s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct  s_tree
{
	t_vec2 	*v;
	double len;
	double rot;
	int branch;
	int size;
	double theta;
	double phi;
	double scl;
	int 	srt_ht;
	char *code;
	char	*x_axiom;
	char	*f_axiom;
	int		init_len;
	double	delta_angle;
	unsigned char c_fmt;
}				t_tree;

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
	float	c_re;
	float	c_im;
	unsigned char fractol;
	unsigned int flags;
	int max_iterations;
	int max_iterations_j;
	t_tree 	*t;
	int b;
	int		*color_map;
	int		c_iter;
}				t_env;

typedef struct  s_line
{
	double dx;
	double dy;
	double p;
	double i;
	double j;
	double j_incr;
	t_vec2 *end;
	t_vec2 *start;
}				t_line;

int main(int argc, char **argv);
unsigned char parse_input(char *argv);
void ft_tree(t_env *e);
void	tree_hook(t_env *e);
t_tree *ft_pop_tree(t_list **list);
t_tree	*pop_tree_state(t_tree *t, t_list **stack);
t_tree	*push_tree_state(t_tree *t, t_list **stack);
t_tree *draw_branch(t_env *e, t_tree *t);
t_line	*get_line_params_x(t_env *e,t_vec2 *p1, t_vec2 *p2);
t_line	*get_line_params_y(t_env *e, t_vec2 *p1, t_vec2 *p2);
int get_color(t_env *e, double i, double j, int center);
void draw_lines_x(t_env *e, t_vec2 *p1, t_vec2 *p2, int center);
void draw_lines_y(t_env *e, t_vec2 *p1, t_vec2 *p2, int center);
int draw_tree(t_env *e);
t_img	*init_image_t(t_env *e);
t_img	*init_image_2(t_env *e);
int ft_draw_tree(t_env *e, t_tree *t, char *code, int i);
char *apply_axioms(t_tree *t, char *src);
char	*generate_code(t_env *e, char *code, int len);
int my_mouse_function_t(int keycode, int i, int h, t_env *e);
int mandlebrot(t_env *e, float r, float c_a, float c_b);
int julia(t_env *e, float a, float b);
t_img *init_image(t_env *e);
t_env	*init_julia(t_env *e);
t_env	*init_mandlebrot(t_env *e);
t_env	*init_tree(t_env *e, char *argv);
t_env	*init_tripper(t_env *e);
t_env	*init_windy(t_env *e);
t_env	*init_ficus(t_env *e);
t_env *init_environment(char *argv);
void	my_loop(t_env *e);
void	draw_m(t_env *e);
void	draw_j(t_env *e);
void	julia_hook(t_env *e);
void	mandlebrot_hook(t_env *e);
// void	tree_hook(t_env *e);
int					*dawn(int i);
int					*dusk(int i);
int					*kryptonite(int i);
int					*dawn(int i);
int					*red_blue(int i);
int					*fire(int i);
int					*ice(int i);
int					*seashore(int i);
int					*kryptonite_center(int i);
int					*seashore_center(int i);
int					*fire_center(int i);
int					*dawn_center(int i);
int					*rainbow_squanch(int i);
int					*tree_map(int i);
t_maps				get_color_map(int i);
t_env				*set_color_map(t_env *e);
int my_loop_hook_j(t_env *e);
int my_key_function_t(int keycode, t_env *e);
int my_key_pressed_j(int keycode, t_env *e);
int my_mouse_function_j(int keycode, int i, int h, t_env *e);
int my_mouse_motion_j(int i , int j , t_env *e);
int my_loop_hook_m(t_env *e);
int my_key_pressed_m(int keycode, t_env *e);
int my_mouse_function_m(int keycode, int i, int h, t_env *e);
int my_mouse_motion_m(int i , int j , t_env *e);
#endif
