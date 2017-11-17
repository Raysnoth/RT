/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:08:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/18 11:32:37 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_obj	*ft_fill_obj2(t_env *env, t_obj *obj)
{
	obj->type = env->parse.type_obj;
	obj->radius = env->tmp.radius;
	obj->angle = env->tmp.angle;
	obj->pos.x = env->tmp.pos.x;
	obj->pos.y = env->tmp.pos.y;
	return (obj);
}

t_obj			*ft_fill_obj(t_env *env)
{
	t_obj		*obj;

	obj = NULL;
	if ((obj = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		ft_error();
	obj = ft_fill_obj2(env, obj);
	obj->pos.z = env->tmp.pos.z;
	obj->angles.x = env->tmp.angles.x;
	obj->angles.y = env->tmp.angles.y;
	obj->angles.z = env->tmp.angles.z;
	obj->angles.h = env->tmp.angles.h;
	obj->color.red = env->tmp.color.red;
	obj->color.green = env->tmp.color.green;
	obj->color.blue = env->tmp.color.blue;
	obj->tex = env->tmp.tex;
	obj->refle = env->tmp.refle;
	obj->refra = env->tmp.refra;
	obj->refra_trans = env->tmp.refra_trans;
	obj->fin[0] = env->tmp.fin[0];
	obj->fin[1] = env->tmp.fin[1];
	obj->finished = env->tmp.finished;
	obj->next = NULL;
	obj->prev = env->tmp_obj;
	return (obj);
}

t_light			*ft_fill_light(t_env *env)
{
	t_light	*light;

	light = NULL;
	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		ft_error();
	light->type = env->parse.type_light;
	light->pos.x = env->tmp.pos.x;
	light->pos.y = env->tmp.pos.y;
	light->pos.z = env->tmp.pos.z;
	light->dir.x = env->tmp.angles.x;
	light->dir.y = env->tmp.angles.y;
	light->dir.z = env->tmp.angles.z;
	light->color.red = env->tmp.color.red;
	light->color.green = env->tmp.color.green;
	light->color.blue = env->tmp.color.blue;
	light->next = NULL;
	light->prev = env->tmp_light;
	return (light);
}
