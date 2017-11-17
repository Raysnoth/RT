/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:56:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 18:20:30 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_create_surfaces(t_env *env)
{
	env->sdl.surf[0] = NULL;
	env->sdl.surf[1] = NULL;
	env->sdl.surf[2] = NULL;
	env->sdl.surf[3] = NULL;
	env->sdl.surf[4] = NULL;
	if ((env->sdl.surf[0] = SDL_LoadBMP("img/checker.bmp")) == NULL)
		ft_error_sdl();
	if ((env->sdl.surf[1] = SDL_LoadBMP("img/moon.bmp")) == NULL)
		ft_error_sdl();
	if ((env->sdl.surf[2] = SDL_LoadBMP("img/soleil.bmp")) == NULL)
		ft_error_sdl();
	if ((env->sdl.surf[3] = SDL_LoadBMP("img/earth.bmp")) == NULL)
		ft_error_sdl();
	if ((env->sdl.surf[4] = SDL_LoadBMP("img/garden.bmp")) == NULL)
		ft_error_sdl();
}

void		ft_init_sdl(t_env *env)
{
	env->sdl.font[0] = NULL;
	env->sdl.font[1] = NULL;
	env->sdl.font[2] = NULL;
	if ((SDL_Init(SDL_INIT_VIDEO) || TTF_Init()) != 0)
		ft_error_sdl();
	if ((env->sdl.win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, (WIDTHR + WIDTHS), HEIGHT, \
			SDL_WINDOW_SHOWN)) == NULL)
		ft_error_sdl();
	if ((env->sdl.rend = SDL_CreateRenderer(env->sdl.win, -1, 0)) == NULL)
		ft_error_sdl();
	env->sdl.format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	if ((env->sdl.font[0] = TTF_OpenFont("fonts/bodoni.ttf", 50)) == NULL)
		ft_error_sdl();
	if ((env->sdl.font[1] = TTF_OpenFont("fonts/bodoni.ttf", 30)) == NULL)
		ft_error_sdl();
	if ((env->sdl.font[2] = TTF_OpenFont("fonts/bodoni.ttf", 25)) == NULL)
		ft_error_sdl();
	env->sdl.keep = 1;
	ft_create_surfaces(env);
}

SDL_Texture	*ft_img_to_tex(t_env *env, char *path)
{
	SDL_Texture	*tex;
	SDL_Surface	*img;

	img = NULL;
	tex = NULL;
	if ((img = SDL_LoadBMP(path)) == NULL)
		ft_error_sdl();
	if ((tex = SDL_CreateTextureFromSurface(env->sdl.rend, \
			img)) == NULL)
		ft_error_sdl();
	SDL_FreeSurface(img);
	return (tex);
}
