/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:25:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 14:20:05 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_env(t_env *env)
{
	env->check.direction = 0;
	env->cam.inc = 50;
	env->amb = 0;
	env->amb_coef = 1;
	env->check.position = 0;
	env->check.radius = 0;
	env->check.color = 0;
	env->parse.type = 0;
	env->parse.type_obj = 0;
	env->parse.objects = 0;
	env->parse.lights = 0;
	env->parse.cam = 0;
	env->parse.nb_line = 0;
	env->parse.com = 0;
	env->parse.line = NULL;
	env->obj = NULL;
	env->light = NULL;
	env->tmp_light = NULL;
	env->tmp_obj = NULL;
	env->tmp.current = NULL;
	ft_memset(&env->sdl.in, 0, sizeof(env->sdl.in));
	ft_memset(&env->filters, 0, sizeof(env->filters));
}

void	ft_init_tmp(t_env *env)
{
	env->tmp.pos.x = 0;
	env->tmp.pos.y = 0;
	env->tmp.pos.z = 0;
	env->tmp.radius = 0;
	env->tmp.angles.x = 0;
	env->tmp.angles.y = 0;
	env->tmp.angles.z = 0;
	env->tmp.angles.h = 0;
	env->tmp.color.red = 0;
	env->tmp.color.green = 0;
	env->tmp.color.blue = 0;
	env->tmp.tex = 0;
	env->tmp.angle = 0;
	env->tmp.refle = 0;
	env->tmp.refra = 0;
	env->tmp.refra_trans = 0;
	env->tmp.fin[0] = 0;
	env->tmp.fin[1] = 0;
	env->tmp.finished = 0;
}

void	ft_init_check(t_env *env)
{
	env->check.position = 0;
	env->check.direction = 0;
	env->check.color = 0;
	env->check.radius = 0;
	env->check.angle = 0;
}

void	ft_init_start(t_env *env)
{
	env->cam.dir.x = 0;
	env->cam.dir.y = 1;
	env->cam.dir.z = 0;
	env->cam.right.x = 1;
	env->cam.right.y = 0;
	env->cam.right.z = 0;
	env->cam.up.x = 0;
	env->cam.up.y = 0;
	env->cam.up.z = 1;
	env->cam.dir = ft_vect_rot(env->cam.dir, env->cam.angles.y, 2);
	env->cam.dir = ft_vect_rot(env->cam.dir, env->cam.angles.z, 1);
	env->cam.dir = (env->cam.dir.x != 1 && env->cam.dir.x != -1) ? \
		ft_vect_rot(env->cam.dir, env->cam.angles.x, 3) : \
		ft_vect_rot(env->cam.dir, env->cam.angles.x, 2);
	ft_calc_ru(env);
	env->cam.view_plane.x = env->cam.pos.x + ((env->cam.dir.x * VIEWPLANED) + \
	(env->cam.up.x * (VIEWPLANEH / 2.0 * F))) - (env->cam.right.x * \
		(VIEWPLANEW / 2.0 * F));
	env->cam.view_plane.y = env->cam.pos.y + ((env->cam.dir.y * VIEWPLANED) + \
	(env->cam.up.y * (VIEWPLANEH / 2.0 * F))) - (env->cam.right.y * \
		(VIEWPLANEW / 2.0 * F));
	env->cam.view_plane.z = env->cam.pos.z + ((env->cam.dir.z * VIEWPLANED) + \
	(env->cam.up.z * (VIEWPLANEH / 2.0 * F))) - (env->cam.right.z * \
		(VIEWPLANEW / 2.0 * F));
}
