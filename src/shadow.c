/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:31:31 by mawasche          #+#    #+#             */
/*   Updated: 2017/08/23 19:17:10 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_shadow(t_env *env)
{
	t_obj	*lst;
	int		power;
	t_light	*tmp;

	lst = env->obj;
	tmp = env->light;
	power = 0;
	env->tmp.darkness = 1;
	while (env->light)
	{
		ft_loop(env);
		power += (env->calc.solution < 0.001) ? 1 : 0;
		env->obj = lst;
		env->light = env->light->next;
	}
	env->tmp.darkness = (power < 4 && env->tmp.darkness != 1) ? \
		env->tmp.darkness * (1 + 0.75 * power) : 1;
	env->light = tmp;
}

void		ft_calc(t_env *env, t_vect test)
{
	void	(*ft_calc[4])(t_env*, t_vect ray_dir, t_vect ray_pos);

	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	ft_calc[env->obj->type - 1](env, test, env->light->solution_point);
}

static void	ft_init_light(t_env *env)
{
	env->shadow.i = 0;
	ft_light_vect(env, 1);
	env->light->norme = sqrt(pow(env->light->light_vect.x, 2) +\
	pow(env->light->light_vect.y, 2) + pow(env->light->light_vect.z, 2));
	env->shadow.test = ft_normalize(env->light->light_vect);
	env->calc.solution = -1;
}

void		ft_loop(t_env *env)
{
	ft_init_light(env);
	while (env->obj)
	{
		ft_calc(env, env->shadow.test);
		if (env->calc.solution > 0.0001 && env->tmp.i != env->shadow.i)
		{
			env->shadow.solution.x = env->calc.solution * env->shadow.test.x;
			env->shadow.solution.y = env->calc.solution * env->shadow.test.y;
			env->shadow.solution.z = env->calc.solution * env->shadow.test.z;
			env->shadow.solution.h = sqrt(pow(env->shadow.solution.x, 2) +\
				pow(env->shadow.solution.y, 2) + pow(env->shadow.solution.z, \
				2));
			if (env->shadow.solution.h < env->light->norme)
			{
				env->tmp.darkness = (env->obj->refra_trans == 0) ? 0.3\
				: (400 + env->obj->refra_trans * 1.0) / 1000;
				break ;
			}
		}
		env->shadow.i++;
		env->obj = env->obj->next;
	}
}
