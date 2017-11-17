/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_again.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 11:29:45 by mawasche          #+#    #+#             */
/*   Updated: 2017/08/23 18:49:11 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_place(t_env *env)
{
	env->light->solution_point.x = env->tmp.ray_pos.x + env->tmp.ray_dir.x *
		env->tmp.solution;
	env->light->solution_point.y = env->tmp.ray_pos.y + env->tmp.ray_dir.y *\
		env->tmp.solution;
	env->light->solution_point.z = env->tmp.ray_pos.z + env->tmp.ray_dir.z *\
		env->tmp.solution;
}

void	ft_light_vect(t_env *env, int mode)
{
	env->light->light_vect.x = env->light->pos.x - env->light->solution_point.x;
	env->light->light_vect.y = env->light->pos.y - env->light->solution_point.y;
	env->light->light_vect.z = env->light->pos.z - env->light->solution_point.z;
	if (mode == 0)
		env->light->light_vect = ft_normalize(env->light->light_vect);
}
