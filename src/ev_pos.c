/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:07:48 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/18 13:51:42 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_ev_pos_rl(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
				env->set.select == 5 || env->set.select == 6 || \
				env->set.select == 8 || env->set.select == 9 || \
				env->set.select == 11 || env->set.select == 12)
			env->set.select = (env->set.select == 2 || \
				env->set.select == 5 || env->set.select == 8 || \
				env->set.select == 11) ? env->set.select + 1 \
				: env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
				env->set.select == 5 || env->set.select == 6 || \
				env->set.select == 8 || env->set.select == 9 || \
				env->set.select == 11 || env->set.select == 12)
			env->set.select = (env->set.select == 2 || \
				env->set.select == 5 || env->set.select == 8 || \
				env->set.select == 11) ? env->set.select + 1 \
				: env->set.select - 1;
	}
}

void		ft_ev_pos_dub(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 11 || env->set.select == 12) ? \
			env->set.select - 9 : env->set.select + 3;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 2 || env->set.select == 3) ? \
			env->set.select + 9 : env->set.select - 3;
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.select = 1;
		env->set.inc = 1;
		env->set.tab = ATTRIBUTES;
	}
}

static void	ft_ev_pos_return2(t_env *env)
{
	if (env->set.select == 8 || env->set.select == 9)
	{
		env->set.obj[3]->pos.y = (env->set.select == 8) ? \
			env->set.obj[3]->pos.y + env->set.inc : env->set.obj[3]->pos.y - \
			env->set.inc;
		ft_refresh(env);
	}
	if (env->set.select == 11 || env->set.select == 12)
	{
		if (env->set.obj[3]->type == PLANE)
		{
			env->set.obj[3]->angles.h = (env->set.select == 11) ? \
				env->set.obj[3]->angles.h + env->set.inc : \
				env->set.obj[3]->angles.h - env->set.inc;
		}
		else
		{
			env->set.obj[3]->pos.z = (env->set.select == 11) ? \
				env->set.obj[3]->pos.z + env->set.inc : \
				env->set.obj[3]->pos.z - env->set.inc;
		}
		ft_refresh(env);
	}
}

void		ft_ev_pos_return1(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		if (env->set.select == 2 || env->set.select == 3)
		{
			env->set.inc = (env->set.select == 2) ? env->set.inc * 2 : \
				env->set.inc / 2;
			env->set.inc = (env->set.inc >= 100) ? 100 : env->set.inc;
			env->set.inc = (env->set.inc <= 1) ? 1 : env->set.inc;
		}
		if (env->set.select == 5 || env->set.select == 6)
		{
			env->set.obj[3]->pos.x = (env->set.select == 5) ? \
				env->set.obj[3]->pos.x + env->set.inc : env->set.obj[3]->pos.x \
				- env->set.inc;
			ft_refresh(env);
		}
		ft_ev_pos_return2(env);
	}
}
