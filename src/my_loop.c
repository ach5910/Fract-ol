/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:12:16 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/06 14:44:51 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_loop(t_env *e)
{
	if (e->fractol & JULIA)
		julia_hook(e);
	else if (e->fractol & MAND)
		mandlebrot_hook(e);
	else if (e->fractol & TREE)
		tree_hook(e);
}
