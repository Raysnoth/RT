/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:07:16 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/18 13:47:42 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_ev_at_dubrl(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 7) ? 1 : env->set.select + 1;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 1) ? 7 : env->set.select - 1;
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		ft_init_set(env);
		env->set.tab = OBJECTS;
	}
}

static void	ft_ev_at_return3(t_env *env)
{
	if (env->set.select == 3)
	{
		env->set.tab = POSTAB;
		env->set.select = 2;
	}
	else if (env->set.select == 4)
	{
		env->set.tab = DIRTAB;
		env->set.select = 2;
	}
	else if (env->set.select == 5)
	{
		env->set.tab = COLTAB;
		env->set.select = 2;
	}
	else if (env->set.select == 6)
	{
		env->set.tab = BASETAB;
		env->set.select = 2;
	}
	if (env->set.select == 7)
	{
		env->set.tab = EFFTAB;
		env->set.select = 2;
	}
}

static void	ft_ev_at_return2(t_env *env)
{
	env->parse.objects--;
	ft_stock_elem(env);
	ft_delete_elem_obj(env);
	ft_init_set(env);
	env->set.del = 1;
	ft_refresh(env);
	env->set.tab = OBJECTS;
	if (env->parse.objects == 0)
	{
		env->obj = NULL;
		env->set.tab = INTERFACE;
	}
}

void		ft_ev_at_return1(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN && env->sdl.in.press == 1)
	{
		if (env->set.select == 1)
		{
			env->parse.objects++;
			ft_add_elem_obj(env);
			env->tmp.current = NULL;
			ft_refresh(env);
			ft_init_set(env);
			env->set.tab = OBJECTS;
		}
		else if (env->set.select == 2)
			ft_ev_at_return2(env);
		else if (env->set.select == 3 || env->set.select == 4 || \
				env->set.select == 5 || env->set.select == 6 || \
				env->set.select == 7)
			ft_ev_at_return3(env);
	}
}
