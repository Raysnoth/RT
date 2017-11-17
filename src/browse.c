/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 11:22:36 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_set_sol(t_env *env, int i, int *n)
{
	env->tmp.current = env->obj;
	env->tmp.solution = env->calc.solution;
	env->tmp.i = i;
	*n += 1;
}

void		ft_browse_list(t_env *env, t_vect ray_dir, t_vect ray_pos, int i)
{
	void	(*ft_calc[4])(t_env*, t_vect ray_dir, t_vect ray_pos);
	t_obj	*lst;
	int		n;

	env->tmp.i = 0;
	n = 0;
	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	lst = env->obj;
	env->calc.solution = -1;
	while (env->obj)
	{
		ft_calc[env->obj->type - 1](env, ray_dir, ray_pos);
		if (env->calc.solution > 0.001 && (n == 0
					|| env->calc.solution < env->tmp.solution))
			ft_set_sol(env, i, &n);
		env->obj = env->obj->next;
		i++;
	}
	env->obj = lst;
}
