/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:22:22 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 12:37:24 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_copy_text_obj(t_env *env)
{
	if ((env->sdl.tset[TTEXT] = SDL_CreateTextureFromSurface(env->sdl.rend, \
			env->sdl.text)) == NULL)
		ft_error_sdl();
	SDL_QueryTexture(env->sdl.tset[TTEXT], NULL, NULL, &env->sdl.rset[DTEXT].w\
		, &env->sdl.rset[DTEXT].h);
	env->sdl.rset[DTEXT].x = ((WIDTHS / 2) - (env->sdl.rset[DTEXT].w / 2));
	env->sdl.rset[DTEXT].y = HEIGHT / 4 + env->set.pos;
	SDL_FreeSurface(env->sdl.text);
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TTEXT], NULL, \
			&env->sdl.rset[DTEXT]);
	env->set.pos = (env->set.obj[1]->next && env->set.nb[1] - env->set.nb[0] \
			< 5) ? env->set.pos + 50 : 0;
}

static void	ft_text_objects2(t_env *env)
{
	if (env->set.block == 0)
	{
		env->set.nb[2] = env->set.nb[1];
		env->set.obj[2] = env->set.obj[1];
	}
}

static void	ft_text_objects(t_env *env)
{
	int		i;
	char	*name;

	i = 0;
	name = NULL;
	while (env->set.obj[1] && ++i <= 6)
	{
		name = (env->set.obj[1]->type == SPHERE) ? ft_freestrjoin(\
			ft_itoa(env->set.nb[1] + 1), " : Sphere ", 1) : name;
		name = (env->set.obj[1]->type == CYL) ? ft_freestrjoin(\
			ft_itoa(env->set.nb[1] + 1), " : Cylinder ", 1) : name;
		name = (env->set.obj[1]->type == CONE) ? ft_freestrjoin(\
			ft_itoa(env->set.nb[1] + 1), " : Cone ", 1) : name;
		name = (env->set.obj[1]->type == PLANE) ? ft_freestrjoin(\
			ft_itoa(env->set.nb[1] + 1), " : Plane ", 1) : name;
		env->sdl.text = TTF_RenderText_Blended(env->sdl.font[1], name, \
			env->set.color[(env->set.select == i) ? 1 : 0]);
		ft_copy_text_obj(env);
		env->set.nb[1]++;
		env->set.obj[1] = env->set.obj[1]->next;
		ft_strdel(&name);
	}
	ft_text_objects2(env);
}

void		ft_s_objects(t_env *env)
{
	if ((env->sdl.tset[TINTER] = SDL_CreateTexture(env->sdl.rend, \
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTHS, \
			HEIGHT)) == NULL)
		ft_error_sdl();
	if (env->set.block == 1)
	{
		env->set.obj[1] = env->set.obj[0];
		env->set.nb[1] = env->set.nb[0];
	}
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.tset[TINTER]);
	if (env->set.obj[0] != env->obj && env->parse.objects - env->set.nb[0] > 6)
		env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/objectsnp.bmp");
	else if (env->set.obj[0] != env->obj)
		env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/objectsp.bmp");
	else if (env->parse.objects - env->set.nb[0] > 6 && env->set.obj[0] \
			== env->obj)
		env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/objectsn.bmp");
	else
		env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/objects.bmp");
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TIMG], NULL, NULL);
	SDL_DestroyTexture(env->sdl.tset[TIMG]);
	ft_text_objects(env);
	SDL_SetRenderTarget(env->sdl.rend, NULL);
	env->set.block = 1;
}
