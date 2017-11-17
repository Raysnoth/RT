/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:03:11 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 20:23:52 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_copy_base_text2(t_env *env, int i)
{
	env->sdl.rset[DTEXT].y = HEIGHT / 4 + env->set.pos;
	SDL_FreeSurface(env->sdl.text);
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TTEXT], NULL, \
			&env->sdl.rset[DTEXT]);
	if ((i % 3 == 0) || i == 1 || i == 4 || i == 7)
		env->set.pos += 40;
	env->set.pos = (i % 9 == 0) ? 0 : env->set.pos;
}

static void	ft_copy_base_text(t_env *env, int i)
{
	if ((env->sdl.tset[TTEXT] = SDL_CreateTextureFromSurface(env->sdl.rend, \
				env->sdl.text)) == NULL)
		ft_error_sdl();
	SDL_QueryTexture(env->sdl.tset[TTEXT], NULL, NULL, &env->sdl.rset[DTEXT].w\
		, &env->sdl.rset[DTEXT].h);
	env->sdl.rset[DTEXT].x = WIDTHS / 2 - (env->sdl.rset[DTEXT].w / 2);
	if (i == 2 || i == 3 || i == 5 || i == 6 || i == 8 || i == 9)
		env->sdl.rset[DTEXT].x = (i == 2 || i == 5 || i == 8) ? \
			env->sdl.rset[DTEXT].x - 20 : env->sdl.rset[DTEXT].x + 20;
	ft_copy_base_text2(env, i);
}

static void	ft_base_text2(t_env *env, char **name, int i)
{
	env->sdl.text = TTF_RenderText_Blended(env->sdl.font[1], *name, \
		env->set.color[(env->set.select == i) ? 1 : 0]);
	ft_copy_base_text(env, i);
}

static void	ft_base_text(t_env *env)
{
	int		i;
	char	*name;

	name = NULL;
	i = 0;
	while (++i <= 9)
	{
		name = (i == 1) ? ft_freestrjoin("Increment :  ", \
			ft_itoa(env->set.inc), 2) : name;
		name = (i == 2) ? ft_strdup("x2") : name;
		name = (i == 3) ? ft_strdup("/2") : name;
		name = (i == 4) ? ft_freestrjoin("Radius :  ", \
			ft_itoa(env->set.obj[3]->radius), 2) : name;
		name = (i == 5) ? ft_strdup("+") : name;
		name = (i == 6) ? ft_strdup("-") : name;
		name = (i == 7) ? ft_freestrjoin("Angle :  ", \
			ft_itoa(env->set.obj[3]->angle), 2) : name;
		name = (i == 8) ? ft_strdup("+") : name;
		name = (i == 9) ? ft_strdup("-") : name;
		ft_base_text2(env, &name, i);
		ft_strdel(&name);
	}
}

void		ft_base_tab(t_env *env)
{
	if ((env->sdl.tset[TINTER] = SDL_CreateTexture(env->sdl.rend, \
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTHS, \
			HEIGHT)) == NULL)
		ft_error_sdl();
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.tset[TINTER]);
	env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/attributes.bmp");
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TIMG], NULL, NULL);
	SDL_DestroyTexture(env->sdl.tset[TIMG]);
	ft_base_text(env);
	SDL_SetRenderTarget(env->sdl.rend, NULL);
}
