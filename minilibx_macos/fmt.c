/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:34:46 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/04 20:35:09 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/include/libft.h"

int main(int argc, char **argv)
{
	int fd;
	char *str;
	int i = 1;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str))
	{
		if (i % 3 == 0)
			ft_printf("0x%s, ", str);
		if (i % 12 == 0)
			ft_printf("\n");
		i++;
	}
	return (0);
}