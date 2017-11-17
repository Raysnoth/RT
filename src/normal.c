/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:18:08 by marnaud           #+#    #+#             */
/*   Updated: 2017/08/23 17:58:40 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_normal_cone(t_env *env)
{
	ft_replace(&env->light->solution_point, env->tmp.current->pos, \
		env->tmp.current->angles);
	env->light->normal_vect.x = 2 * env->light->solution_point.x;
	env->light->normal_vect.y = 2 * env->light->solution_point.y;
	env->light->normal_vect.z = -2 * env->light->solution_point.z;
	env->light->norme = sqrt(pow(env->light->normal_vect.x, 2) +\
		pow(env->light->normal_vect.y, 2) + pow(env->light->normal_vect.z, 2));
	env->light->normal_vect.x /= env->light->norme;
	env->light->normal_vect.y /= env->light->norme;
	env->light->normal_vect.z /= env->light->norme;
}

void	ft_normal_cyl(t_env *env)
{
	ft_replace(&env->light->solution_point, env->tmp.current->pos, \
		env->tmp.current->angles);
	env->light->normal_vect.x = 2 * env->light->solution_point.x;
	env->light->normal_vect.y = 2 * env->light->solution_point.y;
	env->light->normal_vect.z = 1;
	env->light->norme = sqrt(pow(env->light->normal_vect.x, 2) +\
		pow(env->light->normal_vect.y, 2) + pow(env->light->normal_vect.z, 2));
	env->light->normal_vect.x /= env->light->norme;
	env->light->normal_vect.y /= env->light->norme;
	env->light->normal_vect.z /= env->light->norme;
}

void	ft_normal_plane(t_env *env)
{
	env->light->normal_vect.x = env->tmp.current->dir.x;
	env->light->normal_vect.y = env->tmp.current->dir.y;
	env->light->normal_vect.z = env->tmp.current->dir.z;
	env->light->norme = sqrt(pow(env->light->normal_vect.x, 2) +\
		pow(env->light->normal_vect.y, 2) + pow(env->light->normal_vect.z, 2));
	env->light->normal_vect.x /= env->light->norme;
	env->light->normal_vect.y /= env->light->norme;
	env->light->normal_vect.z /= env->light->norme;
}

void	ft_normal_sphere(t_env *env)
{
	env->light->normal_vect.x = env->light->solution_point.x -\
								env->tmp.current->pos.x;
	env->light->normal_vect.y = env->light->solution_point.y -\
								env->tmp.current->pos.y;
	env->light->normal_vect.z = env->light->solution_point.z -\
								env->tmp.current->pos.z;
	env->light->norme = sqrt(pow(env->light->normal_vect.x, 2) +\
		pow(env->light->normal_vect.y, 2) + pow(env->light->normal_vect.z, 2));
	env->light->normal_vect.x /= env->light->norme;
	env->light->normal_vect.y /= env->light->norme;
	env->light->normal_vect.z /= env->light->norme;
}

void	ft_normal_vect(t_env *env)
{
	void	(*ft_normal[4])(t_env *);

	ft_normal[0] = ft_normal_sphere;
	ft_normal[1] = ft_normal_plane;
	ft_normal[2] = ft_normal_cyl;
	ft_normal[3] = ft_normal_cone;
	ft_normal[env->tmp.current->type - 1](env);
}
