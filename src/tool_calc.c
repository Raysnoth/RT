/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:08:26 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 11:27:57 by mawasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vect	ft_calc_sol(t_env *env)
{
	t_vect	sol;

	sol.x = env->cam.pos.x + env->cam.pixel.x * env->tmp.solution;
	sol.y = env->cam.pos.y + env->cam.pixel.y * env->tmp.solution;
	sol.z = env->cam.pos.z + env->cam.pixel.z * env->tmp.solution;
	return (sol);
}

t_vect	ft_normalize(t_vect vect)
{
	t_vect	new;
	double	norme;

	norme = sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2));
	new.x = vect.x / norme;
	new.y = vect.y / norme;
	new.z = vect.z / norme;
	return (new);
}

void	ft_replace(t_vect *solution, t_vect pos_obj, t_vect angles)
{
	solution->x = solution->x - pos_obj.x;
	solution->y = solution->y - pos_obj.y;
	solution->z = solution->z - pos_obj.z;
	ft_redirect(solution, angles);
}

void	ft_redirect(t_vect *solution, t_vect angles)
{
	*solution = (solution->x != 1 && solution->x != -1) ? \
		ft_vect_rot(*solution, -angles.x, 3) : \
		ft_vect_rot(*solution, -angles.x, 1);
	*solution = ft_vect_rot(*solution, -angles.y, 2);
	*solution = ft_vect_rot(*solution, -angles.z, 1);
}

void	ft_direct(t_vect *solution, t_vect angles)
{
	*solution = ft_vect_rot(*solution, angles.z, 1);
	*solution = ft_vect_rot(*solution, angles.y, 2);
	*solution = (solution->x != 1 && solution->x != -1) ? \
		ft_vect_rot(*solution, angles.x, 3) : \
		ft_vect_rot(*solution, angles.x, 1);
}
