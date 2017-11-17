/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:37:30 by mawasche          #+#    #+#             */
/*   Updated: 2017/08/23 19:08:51 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_spotlight(t_env *env)
{
	double			tmp;
	static double	test = 0;

	env->light->norme = sqrt(pow(env->light->dir.x, 2) +\
			pow(env->light->dir.y, 2) + pow(env->light->dir.z, 2));
	env->light->dir.x /= env->light->norme;
	env->light->dir.y /= env->light->norme;
	env->light->dir.z /= env->light->norme;
	tmp = env->light->dir.x * env->light->light_vect.x +\
		env->light->dir.y * env->light->light_vect.y +\
		env->light->dir.z * env->light->light_vect.z;
	env->light->power = (tmp < -(sqrt(3.0) / 2) && tmp > -1) ? \
		env->light->power : 0;
	test = tmp;
}

void	ft_light(t_env *env)
{
	env->tmp.solution_point = env->light->solution_point;
	env->tmp.light = env->light;
	env->tmp.power = 0;
	while (env->light)
	{
		ft_place(env);
		ft_light_vect(env, 0);
		ft_normal_vect(env);
		if (env->tmp.current->type != SPHERE)
			ft_direct(&env->light->normal_vect, env->tmp.current->angles);
		env->light->power = env->light->normal_vect.x * \
			env->light->light_vect.x + env->light->normal_vect.y * \
			env->light->light_vect.y +\
			env->light->normal_vect.z * env->light->light_vect.z;
		if (env->light->power < 0)
			env->light->power = 0;
		if (env->light->type == SPOT)
			ft_spotlight(env);
		env->tmp.power += env->light->power;
		env->light = env->light->next;
	}
	env->light = env->tmp.light;
	env->tmp.power = (env->tmp.power <= 1) ? env->tmp.power : 1;
	env->light->solution_point = env->tmp.solution_point;
}
