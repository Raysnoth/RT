/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 10:51:53 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/18 13:48:54 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_ev_col_rl(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT || \
			env->sdl.event.key.keysym.sym == SDLK_LEFT)
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

void		ft_ev_col_dub(t_env *env)
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

static void	ft_ev_col_return3(t_env *env)
{
	if (env->set.select == 2 || env->set.select == 3)
	{
		env->set.inc = (env->set.select == 2) ? env->set.inc * 2 : \
			env->set.inc / 2;
		env->set.inc = (env->set.inc >= 100) ? 100 : env->set.inc;
		env->set.inc = (env->set.inc <= 1) ? 1 : env->set.inc;
	}
	if (env->set.select == 11 || env->set.select == 12)
	{
		if ((env->set.select == 11 && env->set.obj[3]->color.blue < 255) || \
				(env->set.select == 12 && env->set.obj[3]->color.blue > 0))
		{
			env->set.obj[3]->color.blue = (env->set.select == 11) ? \
				env->set.obj[3]->color.blue + \
			env->set.inc : env->set.obj[3]->color.blue - env->set.inc;
			env->set.obj[3]->color.blue = (env->set.obj[3]->color.blue >= \
				255) ? 255 : env->set.obj[3]->color.blue;
			env->set.obj[3]->color.blue = (env->set.obj[3]->color.blue <= \
				0) ? 0 : env->set.obj[3]->color.blue;
			ft_refresh(env);
		}
	}
}

static void	ft_ev_col_return2(t_env *env)
{
	if (env->set.select == 8 || env->set.select == 9)
	{
		if ((env->set.select == 8 && env->set.obj[3]->color.green < 255) || \
				(env->set.select == 9 && env->set.obj[3]->color.green > 0))
		{
			env->set.obj[3]->color.green = (env->set.select == 8) ? \
				env->set.obj[3]->color.green + env->set.inc : \
				env->set.obj[3]->color.green - env->set.inc;
			env->set.obj[3]->color.green = (env->set.obj[3]->color.green >= \
				255) ? 255 : env->set.obj[3]->color.green;
			env->set.obj[3]->color.green = (env->set.obj[3]->color.green <= \
				0) ? 0 : env->set.obj[3]->color.green;
			ft_refresh(env);
		}
	}
	ft_ev_col_return3(env);
}

void		ft_ev_col_return1(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		if (env->set.select == 5 || env->set.select == 6)
		{
			if ((env->set.select == 5 && env->set.obj[3]->color.red < 255) || \
					(env->set.select == 6 && env->set.obj[3]->color.red > 0))
			{
				env->set.obj[3]->color.red = (env->set.select == 5) ? \
					env->set.obj[3]->color.red + env->set.inc : \
					env->set.obj[3]->color.red - env->set.inc;
				env->set.obj[3]->color.red = (env->set.obj[3]->color.red >= \
					255) ? 255 : env->set.obj[3]->color.red;
				env->set.obj[3]->color.red = (env->set.obj[3]->color.red <= \
					0) ? 0 : env->set.obj[3]->color.red;
				ft_refresh(env);
			}
		}
		ft_ev_col_return2(env);
	}
}
