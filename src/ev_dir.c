/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:15:48 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/18 13:49:27 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_ev_dir_rl(t_env *env)
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

void		ft_ev_dir_dub(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 11 || env->set.select == 12) ? \
			env->set.select - 9 : env->set.select + 3;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 2 || env->set.select == 3) ? \
			env->set.select + 9 : env->set.select - 3;
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.inc = 1;
		env->set.select = 1;
		env->set.tab = ATTRIBUTES;
	}
}

static void	ft_ev_dir_return2(t_env *env)
{
	if (env->set.select == 8 || env->set.select == 9)
	{
		env->set.obj[3]->angles.y = (env->set.select == 8) ? \
			env->set.obj[3]->angles.y + env->set.inc : \
			env->set.obj[3]->angles.y - env->set.inc;
		env->set.obj[3]->angles.y = (env->set.obj[3]->angles.y >= 360) ? \
			env->set.obj[3]->angles.y - 360 : env->set.obj[3]->angles.y;
		env->set.obj[3]->angles.y = (env->set.obj[3]->angles.y <= -360) ? \
			env->set.obj[3]->angles.y + 360 : env->set.obj[3]->angles.y;
		ft_refresh(env);
	}
	if (env->set.select == 11 || env->set.select == 12)
	{
		env->set.obj[3]->angles.z = (env->set.select == 11) ? \
			env->set.obj[3]->angles.z + env->set.inc : \
			env->set.obj[3]->angles.z - env->set.inc;
		env->set.obj[3]->angles.z = (env->set.obj[3]->angles.z >= 360) ? \
			env->set.obj[3]->angles.z - 360 : env->set.obj[3]->angles.z;
		env->set.obj[3]->angles.z = (env->set.obj[3]->angles.z <= -360) ? \
			env->set.obj[3]->angles.z + 360 : env->set.obj[3]->angles.z;
		ft_refresh(env);
	}
}

void		ft_ev_dir_return1(t_env *env)
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
			env->set.obj[3]->angles.x = (env->set.select == 5) ? \
				env->set.obj[3]->angles.x + env->set.inc : \
				env->set.obj[3]->angles.x - env->set.inc;
			env->set.obj[3]->angles.x = (env->set.obj[3]->angles.x >= 360) ? \
				env->set.obj[3]->angles.x - 360 : env->set.obj[3]->angles.x;
			env->set.obj[3]->angles.x = (env->set.obj[3]->angles.x <= -360) ? \
				env->set.obj[3]->angles.x + 360 : env->set.obj[3]->angles.x;
			ft_refresh(env);
		}
		ft_ev_dir_return2(env);
	}
}
