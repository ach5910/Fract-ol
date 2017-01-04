/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:03:23 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/03 23:03:38 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_tree *ft_pop_tree(t_list **list)
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

int ft_draw_tree(t_env *e, t_tree *t, char *code, int i)
{
	t_tree *temp1;
	t_tree *temp2;
	t_list *stack;

	while (code[i])
	{
		if (code[i] == 'F')
			t = draw_branch(e, t);
		else if (code[i] == '+')
			t->rot += t->theta;
		else if (code[i] == '-')
			t->rot -=  t->phi;
		else if (code[i] == '[')
		{
			temp1 = (t_tree*)malloc(sizeof(t_tree));
			temp1->v = (t_vec2*)malloc(sizeof(t_vec2));
			temp1->v->x = t->v->x;
			temp1->v->y = t->v->y;
			temp1->len = t->len;
			temp1->rot = t->rot;
			temp1->theta = t->theta;
			temp1->phi = t->phi;
			ft_lstadd(&stack, ft_lstnew(temp1, sizeof(t_tree)));
			t->branch -= 1;
			t->len *= t->scl;
		}
		else if (code[i] == ']')
		{
			temp2 = (t_tree*)malloc(sizeof(t_tree));
			temp2 = ft_pop_tree(&stack);
			t->v = temp2->v;
			t->len = temp2->len;
			t->rot = temp2->rot;
			t->branch += 1;
		}
		i++;
	}
	return (i);
}

char *apply_axioms(t_tree *t, char *src)
{
	// t_list *stack;
	// t_node *funct;
	char *dest;
	int i = 0;

	dest = ft_strnew(1);
	while (src[i])
	{
		if (src[i] == 'F')
			dest = ft_strapp(dest, t->f_axiom);//FF+[+F-F-F]-[-F+F+F]   //"F[-F][+F]F"
		else if (src[i] == '+')
			dest = ft_strapp(dest, "+");
		else if (src[i] == '-')
			dest = ft_strapp(dest, "-");
		else if (src[i] == '[')
			dest = ft_strapp(dest, "[");
		else if (src[i] == ']')
			dest = ft_strapp(dest, "]");
		else if (src[i] == 'X')
			dest = ft_strapp(dest, t->x_axiom);//"F[+X][-X]FX");//"F[-X][+X]");//FF
		i++;	
	}
	return (dest);
}

char	*generate_code(t_env *e, char *code, int len)
{
	int i = 0;
	while (i < len)
	{
		code = apply_axioms(e->t, code);
		i++;
	}
	return (code);
}

void ft_tree(t_env *e)
{
	char *code;
	code = generate_code(e, e->t->code, e->t->branch);
	e->t->code = ft_strdup(code);
	ft_draw_tree(e, e->t, code, 0);
}
