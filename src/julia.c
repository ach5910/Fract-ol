/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:01:40 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 23:01:54 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rainbow_suanch[256] ={
0xFF0005, 0xFE1100, 0xFE2900, 0xFE4100, 
0xFD5800, 0xFD7000, 0xFD8700, 0xFD9F00, 
0xFCB600, 0xFCCE00, 0xFCE500, 0xFBFB00, 
0xE3FB00, 0xCBFB00, 0xB4FB00, 0x9CFA00, 
0x85FA00, 0x6DFA00, 0x56F900, 0x3FF900, 
0x27F900, 0x10F900, 0x00F808, 0x00F81F, 
0x00F836, 0x00F74D, 0x00F764, 0x00F77B, 
0x00F791, 0x00F6A8, 0x00F6BF, 0x01F6D6, 
0x01F5EC, 0x01E7F5, 0x01D0F5, 0x01B9F5, 
0x01A2F4, 0x018CF4, 0x0175F4, 0x015EF3, 
0x0147F3, 0x0131F3, 0x011AF3, 0x0104F2, 
0x1501F2, 0x2B01F2, 0x4201F1, 0x5801F1, 
0x6E01F1, 0x8501F0, 0x9B01F0, 0xB101F0, 
0xC701F0, 0xDD01EF, 0xEF01EB, 0xEF01D5, 
0xEF01BF, 0xEE01A8, 0xEE0192, 0xEE017C, 
0xED0166, 0xED0150, 0xED0139, 0xED0123,
0xFF0005, 0xFE1100, 0xFE2900, 0xFE4100, 
0xFD5800, 0xFD7000, 0xFD8700, 0xFD9F00, 
0xFCB600, 0xFCCE00, 0xFCE500, 0xFBFB00, 
0xE3FB00, 0xCBFB00, 0xB4FB00, 0x9CFA00, 
0x85FA00, 0x6DFA00, 0x56F900, 0x3FF900, 
0x27F900, 0x10F900, 0x00F808, 0x00F81F, 
0x00F836, 0x00F74D, 0x00F764, 0x00F77B, 
0x00F791, 0x00F6A8, 0x00F6BF, 0x01F6D6, 
0x01F5EC, 0x01E7F5, 0x01D0F5, 0x01B9F5, 
0x01A2F4, 0x018CF4, 0x0175F4, 0x015EF3, 
0x0147F3, 0x0131F3, 0x011AF3, 0x0104F2, 
0x1501F2, 0x2B01F2, 0x4201F1, 0x5801F1, 
0x6E01F1, 0x8501F0, 0x9B01F0, 0xB101F0, 
0xC701F0, 0xDD01EF, 0xEF01EB, 0xEF01D5, 
0xEF01BF, 0xEE01A8, 0xEE0192, 0xEE017C, 
0xED0166, 0xED0150, 0xED0139, 0xED0123,
0xFF0005, 0xFE1100, 0xFE2900, 0xFE4100, 
0xFD5800, 0xFD7000, 0xFD8700, 0xFD9F00, 
0xFCB600, 0xFCCE00, 0xFCE500, 0xFBFB00, 
0xE3FB00, 0xCBFB00, 0xB4FB00, 0x9CFA00, 
0x85FA00, 0x6DFA00, 0x56F900, 0x3FF900, 
0x27F900, 0x10F900, 0x00F808, 0x00F81F, 
0x00F836, 0x00F74D, 0x00F764, 0x00F77B, 
0x00F791, 0x00F6A8, 0x00F6BF, 0x01F6D6, 
0x01F5EC, 0x01E7F5, 0x01D0F5, 0x01B9F5, 
0x01A2F4, 0x018CF4, 0x0175F4, 0x015EF3, 
0x0147F3, 0x0131F3, 0x011AF3, 0x0104F2, 
0x1501F2, 0x2B01F2, 0x4201F1, 0x5801F1, 
0x6E01F1, 0x8501F0, 0x9B01F0, 0xB101F0, 
0xC701F0, 0xDD01EF, 0xEF01EB, 0xEF01D5, 
0xEF01BF, 0xEE01A8, 0xEE0192, 0xEE017C, 
0xED0166, 0xED0150, 0xED0139, 0xED0123,
0xFF0005, 0xFE1100, 0xFE2900, 0xFE4100, 
0xFD5800, 0xFD7000, 0xFD8700, 0xFD9F00, 
0xFCB600, 0xFCCE00, 0xFCE500, 0xFBFB00, 
0xE3FB00, 0xCBFB00, 0xB4FB00, 0x9CFA00, 
0x85FA00, 0x6DFA00, 0x56F900, 0x3FF900, 
0x27F900, 0x10F900, 0x00F808, 0x00F81F, 
0x00F836, 0x00F74D, 0x00F764, 0x00F77B, 
0x00F791, 0x00F6A8, 0x00F6BF, 0x01F6D6, 
0x01F5EC, 0x01E7F5, 0x01D0F5, 0x01B9F5, 
0x01A2F4, 0x018CF4, 0x0175F4, 0x015EF3, 
0x0147F3, 0x0131F3, 0x011AF3, 0x0104F2, 
0x1501F2, 0x2B01F2, 0x4201F1, 0x5801F1, 
0x6E01F1, 0x8501F0, 0x9B01F0, 0xB101F0, 
0xC701F0, 0xDD01EF, 0xEF01EB, 0xEF01D5, 
0xEF01BF, 0xEE01A8, 0xEE0192, 0xEE017C, 
0xED0166, 0xED0150, 0xED0139, 0xED0123};

int julia(t_env *e, float c_a, float c_b, float c_re, float c_im)
{
	int n;
	float a;
	float o_a;
	float b;
	float o_b;
	

	
	n = 0;
	a = c_a;
	b = c_b;
	while (n < e->max_iterations_j)
	{
		o_a = a;
		o_b = b;
		a = o_a * o_a - o_b * o_b + c_re;
		b = 2 * o_a * o_b + c_im;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	return (n);
	
}
void draw_j(t_env *e, float c_re, float c_im)
{
	int i;
	int j;
	int p;
	int ret;
	float c_a;
	float c_b;
	int color;
	float r;

	r = sqrt(pow(WIDTH / 2, 2) + pow(HEIGHT / 2, 2));
	j = 0;
	p = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			c_a = 1.5 * (i - WIDTH / 2) / (WIDTH / 2 );
			c_b = 1.5 * (j - HEIGHT / 2) / (HEIGHT / 2 );
			if ((ret = julia(e, c_a, c_b, c_re, c_im)) == e->max_iterations_j)
				color = 0;
			else
			{
				color = e->color_map[(int)((ret * 64 * e->c_iter / e->max_iterations_j)) % 64];
			}
			// color = sqrt(pow(i - WIDTH / 2, 2) + pow(j - HEIGHT / 2, 2)) * 256 / r;
			// color = dusk[color % 256];
			p = (i * 4) + (j * e->img->size_line);
			e->img->data[p] = color & 0xFF;
			e->img->data[++p] = (color >> 8) & 0xFF;
			e->img->data[++p] = (color >> 16) & 0xFF;
			i++;
		}
		j++;
	}
	i = mlx_put_image_to_window(e->mlx, e->win, e->img->i_ptr, 0, 0);
	mlx_destroy_image(e->mlx, e->img->i_ptr);
	e->img->i_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
}
