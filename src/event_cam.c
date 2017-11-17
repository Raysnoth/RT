/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:27:33 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 13:32:31 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_event_snap(t_env *env)
{
	SDL_Texture	*snap;
	SDL_Surface	*shot;
	char		*name;

	if (env->sdl.event.key.keysym.sym == SDLK_c)
	{
		if ((snap = SDL_CreateTexture(env->sdl.rend, SDL_PIXELFORMAT_RGBA8888, \
				SDL_TEXTUREACCESS_TARGET, WIDTHR, HEIGHT)) == NULL)
			ft_error_sdl();
		SDL_SetRenderTarget(env->sdl.rend, snap);
		SDL_RenderCopy(env->sdl.rend, env->sdl.draw, NULL, NULL);
		if ((shot = SDL_CreateRGBSurface(0, WIDTHR, HEIGHT, 32, 0, 0, 0, 0)) \
				== NULL)
			ft_error_sdl();
		SDL_RenderReadPixels(env->sdl.rend, NULL, \
			SDL_GetWindowPixelFormat(env->sdl.win), shot->pixels, shot->pitch);
		mkdir("./Screenshot", 0775);
		name = ft_freestrjoin("./Screenshot/Screen Shot ", \
		ft_create_date(), 2);
		name = ft_freestrjoin(name, ".bmp", 1);
		SDL_SaveBMP(shot, name);
		ft_strdel(&name);
		SDL_FreeSurface(shot);
		SDL_SetRenderTarget(env->sdl.rend, NULL);
	}
}

static void	ft_event_cam_dub(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_w)
	{
		env->cam.pos.y += env->cam.inc * env->cam.dir.y;
		env->cam.pos.x += env->cam.inc * env->cam.dir.x;
		env->cam.pos.z += env->cam.inc * env->cam.dir.z;
		ft_refresh(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_SPACE)
	{
		env->cam.pos.z += env->cam.inc * env->cam.up.z;
		env->cam.pos.x += env->cam.inc * env->cam.up.x;
		env->cam.pos.y += env->cam.inc * env->cam.up.y;
		ft_refresh(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_x)
	{
		env->cam.pos.z -= env->cam.inc * env->cam.up.z;
		env->cam.pos.x -= env->cam.inc * env->cam.up.x;
		env->cam.pos.y -= env->cam.inc * env->cam.up.y;
		ft_refresh(env);
	}
}

static void	ft_event_cam_rpm(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_KP_PLUS)
		env->cam.inc += 2;
	if (env->sdl.event.key.keysym.sym == SDLK_KP_MINUS)
	{
		env->cam.inc -= 2;
		env->cam.inc = (env->cam.inc < 10) ? 10 : env->cam.inc;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_d)
	{
		env->cam.pos.x += env->cam.inc * env->cam.right.x;
		env->cam.pos.y += env->cam.inc * env->cam.right.y;
		env->cam.pos.z += env->cam.inc * env->cam.right.z;
		ft_refresh(env);
	}
}

static void	ft_event_cam_lr(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_a)
	{
		env->cam.pos.x -= env->cam.inc * env->cam.right.x;
		env->cam.pos.y -= env->cam.inc * env->cam.right.y;
		env->cam.pos.z -= env->cam.inc * env->cam.right.z;
		ft_refresh(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_s)
	{
		env->cam.pos.y -= env->cam.inc * env->cam.dir.y;
		env->cam.pos.x -= env->cam.inc * env->cam.dir.x;
		env->cam.pos.z -= env->cam.inc * env->cam.dir.z;
		ft_refresh(env);
	}
}

void		ft_event_cam(t_env *env)
{
	ft_event_snap(env);
	ft_event_save(env);
	ft_event_cam_rpm(env);
	ft_event_cam_lr(env);
	ft_event_cam_dub(env);
}
