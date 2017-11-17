/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_dup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:18:48 by gauffret          #+#    #+#             */
/*   Updated: 2017/08/23 13:00:19 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_obj	*dup_obj2(t_obj *src, t_obj *new, t_obj *link_src, \
							t_obj *link_dest)
{
	(void)src;
	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		ft_error();
	if (link_dest)
		new->prev = link_dest;
	else
		new->prev = NULL;
	new->next = NULL;
	new->type = link_src->type;
	new->radius = link_src->radius;
	new->angles = dup_vect(link_src->angles);
	new->pos = dup_vect(link_src->pos);
	new->color = dup_color(link_src->color);
	new->angle = link_src->angle;
	new->dir = dup_vect(link_src->dir);
	new->tex = link_src->tex;
	new->refra = link_src->refra;
	new->refra_trans = link_src->refra_trans;
	new->refle = link_src->refle;
	new->fin[0] = link_src->fin[0];
	new->fin[1] = link_src->fin[1];
	new->finished = link_src->finished;
	return (new);
}

t_obj			*dup_obj(t_obj *src, t_env *env)
{
	t_obj	*start;
	t_obj	*link_src;
	t_obj	*link_dest;
	t_obj	*new;

	link_src = src;
	start = NULL;
	new = NULL;
	while (link_src && env->parse.objects > 0)
	{
		new = dup_obj2(src, new, link_src, link_dest);
		if (!start)
		{
			start = new;
			link_dest = start;
		}
		else
		{
			link_dest->next = new;
			link_dest = link_dest->next;
		}
		link_src = link_src->next;
	}
	return (start);
}

static t_light	*dup_light2(t_light *new, t_light *link_dest, t_light *link_src)
{
	if (!(new = (t_light *)malloc(sizeof(t_light))))
		ft_error();
	if (link_dest)
		new->prev = link_dest;
	else
		new->prev = NULL;
	new->next = NULL;
	new->type = link_src->type;
	new->pos = dup_vect(link_src->pos);
	new->solution_point = dup_vect(link_src->solution_point);
	new->normal_vect = dup_vect(link_src->normal_vect);
	new->light_vect = dup_vect(link_src->light_vect);
	new->norme = link_src->norme;
	new->power = link_src->power;
	new->dir = dup_vect(link_src->dir);
	new->color = dup_color(link_src->color);
	return (new);
}

t_light			*dup_light(t_light *src)
{
	t_light	*start;
	t_light	*link_src;
	t_light	*link_dest;
	t_light	*new;

	start = NULL;
	new = NULL;
	link_src = src;
	while (link_src)
	{
		new = dup_light2(new, link_dest, link_src);
		if (!start)
		{
			start = new;
			link_dest = start;
		}
		else
		{
			link_dest->next = new;
			link_dest = link_dest->next;
		}
		link_src = link_src->next;
	}
	return (start);
}

t_tmp			dup_tmp(t_tmp src)
{
	t_tmp	tmp;

	tmp.radius = src.radius;
	tmp.type = src.type;
	tmp.id_o = src.id_o;
	tmp.angle = src.angle;
	tmp.solution = src.solution;
	tmp.i = src.i;
	tmp.darkness = src.darkness;
	tmp.power = src.power;
	tmp.tex = src.tex;
	tmp.refra = src.refra;
	tmp.refle = src.refle;
	tmp.fin[0] = src.fin[0];
	tmp.fin[1] = src.fin[1];
	tmp.finished = src.finished;
	tmp.current = src.current;
	tmp.pos = dup_vect(src.pos);
	tmp.angles = dup_vect(src.angles);
	tmp.color = dup_color(src.color);
	return (tmp);
}
