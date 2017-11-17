/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 16:08:42 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 14:15:24 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_black_white(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_KP_2 && env->sdl.in.press == 1)
	{
		ft_memset(&env->filters.mo, 0, sizeof(env->filters.mo));
		env->filters.neg = 0;
		env->filters.bw[0] = (env->filters.bw[0] == 0) ? 1 : 0;
		ft_browse_pixels(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_KP_1)
	{
		if (env->filters.bw[0] == 1)
			env->filters.bw[2] = (env->filters.bw[2] > -255) ? \
				env->filters.bw[2] - 5 : env->filters.bw[2];
		ft_refresh(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_KP_3)
	{
		if (env->filters.bw[0] == 1)
			env->filters.bw[2] = (env->filters.bw[2] < 255) ? \
				env->filters.bw[2] + 5 : env->filters.bw[2];
		ft_refresh(env);
	}
}

static void	ft_neg(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_KP_6 && env->sdl.in.press == 1)
	{
		ft_memset(&env->filters.bw, 0, sizeof(env->filters.bw));
		env->filters.mo[0] = 0;
		env->filters.mo[1] = 0;
		env->filters.neg = 0;
		env->filters.mo[2] = (env->filters.mo[2] == 0) ? 1 : 0;
		ft_refresh(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_KP_8 && env->sdl.in.press == 1)
	{
		ft_memset(&env->filters.mo, 0, sizeof(env->filters.mo));
		ft_memset(&env->filters.bw, 0, sizeof(env->filters.bw));
		env->filters.neg = (env->filters.neg == 0) ? 1 : 0;
		ft_refresh(env);
	}
}

static void	ft_mono(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_KP_4 && env->sdl.in.press == 1)
	{
		ft_memset(&env->filters.bw, 0, sizeof(env->filters.bw));
		env->filters.mo[1] = 0;
		env->filters.mo[2] = 0;
		env->filters.neg = 0;
		env->filters.mo[0] = (env->filters.mo[0] == 0) ? 1 : 0;
		ft_refresh(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_KP_5 && env->sdl.in.press == 1)
	{
		ft_memset(&env->filters.bw, 0, sizeof(env->filters.bw));
		env->filters.mo[0] = 0;
		env->filters.neg = 0;
		env->filters.mo[2] = 0;
		env->filters.mo[1] = (env->filters.mo[1] == 0) ? 1 : 0;
		ft_refresh(env);
	}
}

void		ft_filters(t_env *env)
{
	ft_black_white(env);
	ft_mono(env);
	ft_neg(env);
}
