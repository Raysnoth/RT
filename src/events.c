/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:49:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/18 14:06:19 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_event(t_env *env)
{
	void	(*tab[8])(t_env *);

	tab[0] = ft_ev_inter;
	tab[1] = ft_ev_obj;
	tab[2] = ft_ev_at;
	tab[3] = ft_ev_pos;
	tab[4] = ft_ev_dir;
	tab[5] = ft_ev_col;
	tab[6] = ft_ev_base;
	tab[7] = ft_ev_eff;
	tab[env->set.tab](env);
}

void		ft_ev_base_return3(t_env *env)
{
	if (env->set.obj[3]->finished == 1 && (env->set.select == 16 || \
			env->set.select == 17))
	{
		env->set.obj[3]->fin[1] = (env->set.select == 16) ? \
			env->set.obj[3]->fin[1] + env->set.inc : \
			env->set.obj[3]->fin[1] - env->set.inc;
		ft_refresh(env);
	}
}
