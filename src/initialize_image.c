/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initailize_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:51:12 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 22:51:16 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	*init_image(t_env *e)
{
	t_img *img;

	img = (t_img*)malloc(sizeof(t_img));
	img->i_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	img->w = WIDTH / 2;
	img->h = HEIGHT / 2;
	img->data = mlx_get_data_addr(img->i_ptr, &img->bpp, &img->size_line,
		&img->endian);
	return (img);
}

t_img	*init_image_t(t_env *e)
{
	t_img *img;

	img = (t_img*)malloc(sizeof(t_img));
	img->i_ptr = mlx_new_image(e->mlx, W_T, H_T);
	img->w = W_T / 2;
	img->h = H_T / 2;
	img->data = mlx_get_data_addr(img->i_ptr, &img->bpp, &img->size_line,
		&img->endian);
	return (img);
}

t_img	*init_image_2(t_env *e)
{
	t_img *img;

	img = (t_img*)malloc(sizeof(t_img));
	img->i_ptr = mlx_new_image(e->mlx, W_2, H_2);
	img->w = W_2 / 2;
	img->h = H_2 / 2;
	img->data = mlx_get_data_addr(img->i_ptr, &img->bpp, &img->size_line,
		&img->endian);
	return (img);
}
