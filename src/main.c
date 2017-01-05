/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:47:44 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/06 14:43:58 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned char parse_input(char *argv)
{
	if (ft_strcmp(argv, "julia") == 0)
		return (JULIA);
	if (ft_strcmp(argv, "mandelbrot") == 0)
		return (MAND);
	if (ft_strncmp(argv, "tree", 4) == 0)
		return (TREE);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env *e;

	if (argc == 2)
	{
		if ((e = init_environment(argv[1])) == NULL)
			return (0);
		if (e->fractol & TREE)
			ft_tree(e);
		else if (e->fractol & MAND)
			draw_m(e);
		else if (e->fractol & JULIA)
		{
			draw_m(e);
			draw_j(e);
		}
		if (e != NULL)
			my_loop(e);
	}
	ft_printf("usage: ./fractol julia\n       ./fractol mandelbrot\n");
	ft_printf("       ./fractol tree1\n       ./fractol tree2\n");
	ft_printf("       ./fractol tree3\n");
	return (0);
}
