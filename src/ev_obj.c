/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:56:28 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/18 13:50:59 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_ev_obj_duret(t_env *env)
{
	int		i;

	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == (env->set.nb[2] - \
			env->set.nb[0])) ? 1 : env->set.select + 1;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 1) ? (env->set.nb[2] - \
			env->set.nb[0]) : env->set.select - 1;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN && env->sdl.in.press == 1)
	{
		if (env->obj)
		{
			i = 0;
			while (env->set.obj[3] && ++i < (6 * env->set.p[0] + \
											env->set.select))
				env->set.obj[3] = env->set.obj[3]->next;
			env->set.tab = ATTRIBUTES;
			env->set.pos = 0;
			env->set.id_o = 6 * env->set.p[0] + env->set.select;
			env->set.select = 1;
		}
	}
}

void	ft_ev_obj_rb(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT && env->parse.objects - \
			env->set.nb[0] > 6)
	{
		env->set.p[0]++;
		env->set.block = 0;
		env->set.pos = 0;
		env->set.obj[0] = env->set.obj[2];
		env->set.obj[1] = env->set.obj[0];
		env->set.select = 1;
		env->set.nb[0] = env->set.nb[2];
		env->set.nb[1] = env->set.nb[0];
		SDL_DestroyTexture(env->sdl.tset[TINTER]);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.tab = INTERFACE;
		env->set.pos = 0;
		env->set.select = 1;
		env->set.obj[3] = env->obj;
	}
}

void	ft_ev_obj_l(t_env *env)
{
	int		i;

	if (env->sdl.event.key.keysym.sym == SDLK_LEFT && env->set.obj[0] != \
		env->obj)
	{
		env->set.p[0]--;
		i = 0;
		while (env->set.obj[0] && i <= 5)
		{
			env->set.obj[0] = env->set.obj[0]->prev;
			env->set.nb[0]--;
			i++;
		}
		env->set.block = 0;
		env->set.pos = 0;
		env->set.obj[1] = env->set.obj[0];
		env->set.select = 1;
		env->set.nb[1] = env->set.nb[0];
		SDL_DestroyTexture(env->sdl.tset[TINTER]);
	}
}

void	ft_ev_obj_u(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_u && env->set.del == 1)
	{
		ft_undelete(env);
		ft_init_set(env);
		env->set.tab = OBJECTS;
		env->parse.objects++;
		ft_refresh(env);
	}
}
