/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:47:02 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 13:49:05 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_delete_elem_obj2(t_env *env, int i, t_obj *tmp, t_obj *start)
{
	while (start && ++i < env->set.id_o)
	{
		if (i + 1 && i + 1 == env->set.id_o)
		{
			tmp = start->next;
			start->next = tmp->next;
			start->next->prev = start;
			free(tmp);
		}
		start = start->next;
	}
}

void	ft_delete_elem_obj(t_env *env)
{
	t_obj	*start;
	t_obj	*tmp;

	tmp = NULL;
	start = env->obj;
	if (env->set.id_o == 1 && env->set.obj[3]->next == NULL)
	{
		free(env->obj);
		env->obj = NULL;
	}
	else if (env->set.obj[3]->next == NULL)
	{
		tmp = env->set.obj[3]->prev;
		tmp->next = NULL;
		free(env->set.obj[3]);
	}
	else if (env->set.id_o == 1)
	{
		tmp = env->obj;
		env->obj = env->obj->next;
		free(tmp);
	}
	else
		ft_delete_elem_obj2(env, 0, tmp, start);
}

t_obj	*ft_undelete_init(t_env *env)
{
	t_obj	*new;

	new = NULL;
	if ((new = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		ft_error();
	new->type = env->parse.type_obj;
	new->pos = dup_vect(env->tmp.pos);
	new->angles = dup_vect(env->tmp.angles);
	new->refle = env->tmp.refle;
	new->refra = env->tmp.refra;
	new->refra_trans = env->tmp.refra_trans;
	new->color = dup_color(env->tmp.color);
	new->tex = env->tmp.tex;
	new->angle = env->tmp.angle;
	new->radius = env->tmp.radius;
	new->finished = env->tmp.finished;
	new->fin[0] = env->tmp.fin[0];
	new->fin[1] = env->tmp.fin[1];
	new->next = NULL;
	return (new);
}

void	ft_undelete2(t_env *env, t_obj *start, t_obj *new)
{
	int		i;

	i = 1;
	while (start && i < env->tmp.id_o)
	{
		if (i + 1 && i + 1 == env->tmp.id_o)
		{
			start->next->prev = new;
			new->next = start->next;
			start->next = new;
			new->prev = start;
		}
		start = start->next;
		i++;
	}
}

void	ft_undelete(t_env *env)
{
	t_obj	*start;
	t_obj	*new;

	start = NULL;
	new = ft_undelete_init(env);
	if (env->obj)
		start = env->obj;
	new->prev = start;
	if (env->tmp.id_o == 1)
	{
		new->prev = NULL;
		if (start)
			new->next = start;
		if (start)
			start->prev = new;
		env->obj = new;
	}
	else if ((env->tmp.id_o - 1) == env->parse.objects)
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
	else
		ft_undelete2(env, start, new);
}
