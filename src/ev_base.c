/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:51:05 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 20:22:55 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_ev_base_rlb(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT || \
			env->sdl.event.key.keysym.sym == SDLK_LEFT)
		if ((env->set.select % 3 == 0 && env->set.select < 12) || \
				env->set.select == 2 || env->set.select == 5 || \
				env->set.select == 8)
			env->set.select = (env->set.select == 2 || env->set.select == 5 \
			|| env->set.select == 8) ? \
			env->set.select + 1 : env->set.select - 1;
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.select = 1;
		env->set.inc = 1;
		env->set.tab = ATTRIBUTES;
	}
}

void		ft_ev_base_down(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
				env->set.select == 5 || env->set.select == 6)
			env->set.select += 3;
		else if (env->set.select == 8 || env->set.select == 9)
			env->set.select -= 6;
	}
}

void		ft_ev_base_up(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
	{
		if (env->set.select == 5 || env->set.select == 6 || env->set.select == \
				8 || env->set.select == 9)
			env->set.select -= 3;
		else if (env->set.select == 2 || env->set.select == 3)
			env->set.select += 6;
	}
}

static void	ft_ev_base_return2(t_env *env)
{
	if ((env->set.select == 8 || (env->set.select == 9 && \
			env->set.obj[3]->angle > 1)) && env->set.obj[3]->type == CONE)
	{
		env->set.obj[3]->angle = (env->set.select == 8) ? \
			env->set.obj[3]->angle + env->set.inc : env->set.obj[3]->angle - \
			env->set.inc;
		env->set.obj[3]->angle = (env->set.obj[3]->angle < 1) ? 1 : \
			env->set.obj[3]->angle;
		env->set.obj[3]->angle = (env->set.obj[3]->angle > 90) ? \
			env->set.obj[3]->angle - 90 : env->set.obj[3]->angle;
		ft_refresh(env);
	}
	ft_ev_base_return3(env);
}

void		ft_ev_base_return1(t_env *env)
{
	if (env->set.select == 2 || env->set.select == 3)
	{
		env->set.inc = (env->set.select == 2) ? env->set.inc * 2 : \
			env->set.inc / 2;
		env->set.inc = (env->set.inc >= 100) ? 100 : env->set.inc;
		env->set.inc = (env->set.inc <= 1) ? 1 : env->set.inc;
	}
	if ((env->set.select == 5 || (env->set.select == 6 && \
			env->set.obj[3]->radius > 1)) && (env->set.obj[3]->type == SPHERE \
			|| env->set.obj[3]->type == CYL))
	{
		env->set.obj[3]->radius = (env->set.select == 5) ? \
			env->set.obj[3]->radius + env->set.inc : \
			env->set.obj[3]->radius - env->set.inc;
		env->set.obj[3]->radius = (env->set.obj[3]->radius < 1) ? 1 : \
			env->set.obj[3]->radius;
		ft_refresh(env);
	}
	ft_ev_base_return2(env);
}
