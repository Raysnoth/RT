/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:48:55 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 13:49:07 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_add_elem_obj(t_env *env)
{
	t_obj	*tmp;
	t_obj	*obj;

	tmp = env->set.obj[3];
	while (tmp->next)
		tmp = tmp->next;
	if ((obj = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		ft_error();
	obj->type = env->set.obj[3]->type;
	obj->radius = env->set.obj[3]->radius;
	obj->angle = env->set.obj[3]->angle;
	obj->pos = dup_vect(env->set.obj[3]->pos);
	obj->angles = dup_vect(env->set.obj[3]->angles);
	obj->color = dup_color(env->set.obj[3]->color);
	obj->tex = env->set.obj[3]->tex;
	obj->refle = env->set.obj[3]->refle;
	obj->refra = env->set.obj[3]->refra;
	obj->refra_trans = env->set.obj[3]->refra_trans;
	obj->finished = env->set.obj[3]->finished;
	obj->fin[0] = env->set.obj[3]->fin[0];
	obj->fin[1] = env->set.obj[3]->fin[1];
	obj->next = NULL;
	obj->prev = tmp;
	tmp->next = obj;
}

void	ft_stock_elem(t_env *env)
{
	env->parse.type_obj = env->set.obj[3]->type;
	env->tmp.pos.x = env->set.obj[3]->pos.x;
	env->tmp.pos.y = env->set.obj[3]->pos.y;
	env->tmp.pos.z = env->set.obj[3]->pos.z;
	env->tmp.angles.x = env->set.obj[3]->angles.x;
	env->tmp.angles.y = env->set.obj[3]->angles.y;
	env->tmp.angles.z = env->set.obj[3]->angles.z;
	env->tmp.angles.h = env->set.obj[3]->angles.h;
	env->tmp.color.red = env->set.obj[3]->color.red;
	env->tmp.color.green = env->set.obj[3]->color.green;
	env->tmp.color.blue = env->set.obj[3]->color.blue;
	env->tmp.tex = env->set.obj[3]->tex;
	env->tmp.refle = env->set.obj[3]->refle;
	env->tmp.refra = env->set.obj[3]->refra;
	env->tmp.refra_trans = env->set.obj[3]->refra_trans;
	env->tmp.angle = env->set.obj[3]->angle;
	env->tmp.radius = env->set.obj[3]->radius;
	env->tmp.finished = env->set.obj[3]->finished;
	env->tmp.fin[0] = env->set.obj[3]->fin[0];
	env->tmp.fin[1] = env->set.obj[3]->fin[1];
	env->tmp.id_o = env->set.id_o;
}
