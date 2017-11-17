/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:28:59 by marnaud           #+#    #+#             */
/*   Updated: 2017/08/23 12:58:50 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_reflexion(t_env *env)
{
	int		refle_lvl;

	refle_lvl = env->tmp.current->refle;
	env->tmp.ray_pos = env->light->solution_point;
	env->tmp.ray_dir = ft_vect_op(env->tmp.ray_dir, '-',\
		ft_vect_op2(2 * ft_scalar(env->light->normal_vect,\
		env->tmp.ray_dir), '*', env->light->normal_vect));
	env->tmp.solution = 0;
	ft_browse_list(env, env->tmp.ray_dir, env->tmp.ray_pos, 0);
}
