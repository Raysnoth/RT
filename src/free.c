/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:55:55 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 17:13:27 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_free(t_env *env)
{
	SDL_FreeFormat(env->sdl.format);
	SDL_FreeSurface(env->sdl.surf[0]);
	SDL_FreeSurface(env->sdl.surf[1]);
	SDL_FreeSurface(env->sdl.surf[2]);
	SDL_DestroyTexture(env->sdl.draw);
	SDL_DestroyWindow(env->sdl.win);
	SDL_DestroyRenderer(env->sdl.rend);
	ft_free_obj(env->obj);
	ft_free_light(env->light);
	TTF_CloseFont(env->sdl.font[0]);
	TTF_CloseFont(env->sdl.font[1]);
	TTF_CloseFont(env->sdl.font[2]);
	TTF_Quit();
	SDL_Quit();
}

void	ft_free_obj(t_obj *obj)
{
	t_obj	*link;
	t_obj	*del;

	link = obj;
	while (link)
	{
		del = link;
		link = link->next;
		del->next = NULL;
		free(del);
		del = NULL;
	}
}

void	ft_free_light(t_light *light)
{
	t_light	*link;
	t_light	*del;

	link = light;
	while (link)
	{
		del = link;
		link = link->next;
		del->next = NULL;
		free(del);
		del = NULL;
	}
}
