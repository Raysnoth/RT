/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_eff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:54:10 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 11:15:07 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_ev_eff_rlb(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT || \
			env->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
				env->set.select == 5 || env->set.select == 6 || \
				env->set.select == 8 || env->set.select == 9 || \
				env->set.select == 11 || env->set.select == 12)
			env->set.select = (env->set.select == 2 || env->set.select == 5 ||\
				env->set.select == 8 || env->set.select == 11) ? \
				env->set.select + 1 : env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.select = 1;
		env->set.tab = ATTRIBUTES;
		env->set.inc = 1;
	}
}

void		ft_ev_eff_du(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 11 || env->set.select == 12) ? \
			env->set.select - 9 : env->set.select + 3;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 2 || env->set.select == 3) ? \
			env->set.select + 9 : env->set.select - 3;
}

static void	ft_ev_eff_return2(t_env *env)
{
	if ((env->set.select == 8 && env->set.obj[3]->refra < 7) || \
			(env->set.select == 9 && env->set.obj[3]->refra > 0))
	{
		env->set.obj[3]->refra = (env->set.select == 8) ? \
			env->set.obj[3]->refra + env->set.inc : env->set.obj[3]->refra - \
			env->set.inc;
		env->set.obj[3]->refra = (env->set.obj[3]->refra >= 7) ? 7 : \
			env->set.obj[3]->refra;
		env->set.obj[3]->refra = (env->set.obj[3]->refra <= 0) ? 0 : \
			env->set.obj[3]->refra;
		ft_refresh(env);
	}
	if ((env->set.select == 11 && env->set.obj[3]->refra_trans < 100) || \
			(env->set.select == 12 && env->set.obj[3]->refra_trans > 0))
	{
		env->set.obj[3]->refra_trans = (env->set.select == 11) ? \
			env->set.obj[3]->refra_trans + env->set.inc : \
			env->set.obj[3]->refra_trans - env->set.inc;
		env->set.obj[3]->refra_trans = (env->set.obj[3]->refra_trans >= 100) ? \
			100 : env->set.obj[3]->refra_trans;
		env->set.obj[3]->refra_trans = (env->set.obj[3]->refra_trans <= 0) ? 0 \
			: env->set.obj[3]->refra_trans;
		ft_refresh(env);
	}
}

void		ft_ev_eff_return1(t_env *env)
{
	if (env->set.select == 2 || env->set.select == 3)
	{
		env->set.inc = (env->set.select == 2) ? env->set.inc * 2 : \
			env->set.inc / 2;
		env->set.inc = (env->set.inc >= 100) ? 100 : env->set.inc;
		env->set.inc = (env->set.inc <= 1) ? 1 : env->set.inc;
		ft_refresh(env);
	}
	if ((env->set.select == 5 && env->set.obj[3]->refle < 100) || \
			(env->set.select == 6 && env->set.obj[3]->refle > 0))
	{
		env->set.obj[3]->refle = (env->set.select == 5) ? \
			env->set.obj[3]->refle + env->set.inc : env->set.obj[3]->refle - \
			env->set.inc;
		env->set.obj[3]->refle = (env->set.obj[3]->refle >= 100) ? 100 : \
			env->set.obj[3]->refle;
		env->set.obj[3]->refle = (env->set.obj[3]->refle <= 0) ? 0 : \
			env->set.obj[3]->refle;
		ft_refresh(env);
	}
	ft_ev_eff_return2(env);
}
