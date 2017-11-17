/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:29:34 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 16:19:52 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_display(t_env *env)
{
	SDL_SetRenderDrawColor(env->sdl.rend, 255, 255, 255, 255);
	SDL_RenderClear(env->sdl.rend);
	env->sdl.rt.x = 0;
	env->sdl.rt.y = 0;
	env->sdl.rt.w = WIDTHR;
	env->sdl.rt.h = HEIGHT;
	env->sdl.rset[DINTER].x = WIDTHR;
	env->sdl.rset[DINTER].y = 0;
	env->sdl.rset[DINTER].w = WIDTHS;
	env->sdl.rset[DINTER].h = HEIGHT;
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TINTER], NULL, \
			&env->sdl.rset[DINTER]);
	SDL_RenderCopy(env->sdl.rend, env->sdl.draw, NULL, &env->sdl.rt);
	SDL_DestroyTexture(env->sdl.tset[TINTER]);
	SDL_RenderPresent(env->sdl.rend);
}

void		ft_refresh(t_env *env)
{
	SDL_DestroyTexture(env->sdl.draw);
	ft_browse_pixels(env);
}

static void	new_color(t_env *env, int deep, int rate[5], t_color tab[5])
{
	while (deep > 0)
	{
		tab[deep - 1].red = (tab[deep - 1].red * rate[deep - 1]\
				+ tab[deep].red * (100 - rate[deep - 1])) / 100;
		tab[deep - 1].green = (tab[deep - 1].green * rate[deep - 1]\
				+ tab[deep].green * (100 - rate[deep - 1])) / 100;
		tab[deep - 1].blue = (tab[deep - 1].blue * rate[deep - 1]\
				+ tab[deep].blue * (100 - rate[deep - 1])) / 100;
		deep--;
	}
	env->tmp.color = tab[0];
}

static int	ft_set_rate(t_env *env)
{
	int	rate;

	if (env->tmp.current->refle > 0)
	{
		rate = 100 - env->tmp.current->refle;
		ft_reflexion(env);
		return (rate);
	}
	else if (env->tmp.current->refra_trans > 0)
	{
		rate = (100 - env->tmp.current->refra_trans > 10) ? 100 \
			- env->tmp.current->refra_trans : 110 - \
			env->tmp.current->refra_trans;
		ft_refraction(env);
		return (rate);
	}
	else
		return (-1);
}

void		ft_option_visu(t_env *env)
{
	int		deep;
	int		rate[5];
	t_color	tab[5];

	deep = 0;
	while (deep < 5)
	{
		if (env->tmp.solution > 0)
		{
			tab[deep] = ft_chose_color(env);
			if ((rate[deep] = ft_set_rate(env)) == -1)
				break ;
			deep++;
		}
		else
		{
			tab[deep].red = 0;
			tab[deep].green = 0;
			tab[deep].blue = 0;
			break ;
		}
	}
	new_color(env, deep, rate, tab);
}
