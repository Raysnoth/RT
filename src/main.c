/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:42:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 14:29:20 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		ft_main_wh(t_env *env)
{
	SDL_WaitEvent(&env->sdl.event);
	if (env->sdl.event.type == SDL_QUIT)
		env->sdl.keep = 0;
	if (env->sdl.event.type == SDL_KEYDOWN)
	{
		env->sdl.in.press++;
		ft_event_cam(env);
		ft_event(env);
		if (env->sdl.event.key.keysym.sym == SDLK_ESCAPE)
			env->sdl.keep = 0;
	}
	if (env->sdl.event.type == SDL_KEYUP)
		env->sdl.in.press = 0;
	ft_settings(env);
	ft_filters(env);
	ft_update_mouse(env);
	ft_cam_mouse(env);
	ft_display(env);
}

static t_light	*ft_create_light(void)
{
	t_light	*light;

	light = NULL;
	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		ft_error();
	light->type = BASIC;
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 3000;
	light->dir.x = 0;
	light->dir.y = 0;
	light->dir.z = 0;
	light->color.red = 0;
	light->color.green = 0;
	light->color.blue = 0;
	light->next = NULL;
	light->prev = NULL;
	return (light);
}

int				main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		ft_parse(&env, av[1]);
		if (env.parse.lights == 0)
		{
			env.amb = 1;
			env.light = ft_create_light();
		}
		ft_init_sdl(&env);
		ft_init_set(&env);
		ft_settings(&env);
		ft_browse_pixels(&env);
		ft_display(&env);
		while (env.sdl.keep)
			ft_main_wh(&env);
		ft_free(&env);
		SDL_DestroyRenderer(env.sdl.rend);
		SDL_DestroyWindow(env.sdl.win);
		SDL_Quit();
	}
	else
		ft_putendl("Usage : ./rt scene");
	return (0);
}
