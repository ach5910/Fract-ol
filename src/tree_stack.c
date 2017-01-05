/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:53:59 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/04 12:54:12 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_tree	*ft_pop_tree(t_list **list)
{
	t_tree *data;
	t_list *temp;

	if (!*list)
		return (NULL);
	data = (*list)->content;
	if ((*list)->next)
	{
		(*list) = (*list)->next;
	}
	return (data);
}

t_tree	*push_tree_state(t_tree *t, t_list **stack)
{
	t_tree *temp1;

	temp1 = (t_tree*)malloc(sizeof(t_tree));
	temp1->v = (t_vec2*)malloc(sizeof(t_vec2));
	temp1 = t;
	ft_lstadd(stack, ft_lstnew(temp1, sizeof(t_tree)));
	t->branch -= 1;
	t->len *= t->scl;
	return (t);
}

t_tree	*pop_tree_state(t_tree *t, t_list **stack)
{
	t_tree *temp2;

	temp2 = ft_pop_tree(stack);
	t->v = temp2->v;
	t->len = temp2->len;
	t->rot = temp2->rot;
	ft_memdel((void **)&temp2);
	t->branch += 1;
	return (t);
}
