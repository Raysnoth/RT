/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:56:01 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 20:07:50 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

Uint32			obtenir_pixel(SDL_Surface *surface, int x, int y)
{
	int		nb_octet_pixel;
	Uint8	*p;

	nb_octet_pixel = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * nb_octet_pixel;
	if (surface == NULL)
		return (0);
	if (nb_octet_pixel == 1)
		return (*p);
	else if (nb_octet_pixel == 2)
		return (*(Uint16 *)p);
	else if (nb_octet_pixel == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (nb_octet_pixel == 4)
		return (*(Uint32 *)p);
	else
		return (0);
}

static t_color	ft_filter_mo(t_env *env, t_color color)
{
	t_color color_red;
	t_color color_blue;
	t_color color_green;

	color_red.red = color.red;
	color_red.green = 0;
	color_red.blue = 0;
	color_green.red = 0;
	color_green.green = color.green;
	color_green.blue = 0;
	color_blue.red = 0;
	color_blue.green = 0;
	color_blue.blue = color.blue;
	color = (env->filters.mo[0] == 1) ? color_red : color;
	color = (env->filters.mo[1] == 1) ? color_green : color;
	color = (env->filters.mo[2] == 1) ? color_blue : color;
	return (color);
}

static t_color	ft_chose_filter(t_env *env, t_color color)
{
	if (env->filters.bw[0])
	{
		env->filters.bw[1] = (color.red + color.green + color.blue) / 3 + \
			env->filters.bw[2];
		env->filters.bw[1] = (env->filters.bw[1] > 255) ? 255 : \
			env->filters.bw[1];
		env->filters.bw[1] = (env->filters.bw[1] < 0) ? 0 : \
			env->filters.bw[1];
		color.red = env->filters.bw[1];
		color.green = env->filters.bw[1];
		color.blue = env->filters.bw[1];
	}
	else if (env->filters.neg)
	{
		color.red = 255 - color.red;
		color.green = 255 - color.green;
		color.blue = 255 - color.blue;
	}
	else if (env->filters.mo[0] || env->filters.mo[1] || env->filters.mo[2])
		color = ft_filter_mo(env, color);
	return (color);
}

t_color			ft_option_col(t_env *env, t_color color)
{
	env->tmp.light = env->light;
	color = ft_chose_filter(env, color);
	while (env->light)
	{
		if ((acos(env->light->power) * 180 / M_PI < 10) && env->amb == 0 && \
				env->light->norme < 2000)
		{
			color.red = ((255 * (10 - acos(env->light->power) * 180 / M_PI)) +\
			(color.red * acos(env->light->power) * 180 / M_PI)) / 10;
			color.green = ((255 * (10 - acos(env->light->power) * 180 / M_PI)) \
			+ (color.green * acos(env->light->power) * 180 / M_PI)) / 10;
			color.blue = ((255 * (10 - acos(env->light->power) * 180 / M_PI)) +\
			(color.blue * acos(env->light->power) * 180 / M_PI)) / 10;
		}
		env->light = env->light->next;
	}
	env->light = env->tmp.light;
	return (color);
}

t_color			ft_chose_color(t_env *env)
{
	t_color color;
	t_color tmp;

	ft_place(env);
	ft_light(env);
	ft_shadow(env);
	tmp = env->tmp.current->color;
	if (env->tmp.current->tex > 0)
		env->tmp.current->color = ft_texture(env);
	color.red = (env->light->norme < 5000) ? env->tmp.current->color.red * \
		env->tmp.power * (env->tmp.darkness) * \
		(1 - (env->light->norme / 5000)) : 0;
	color.green = (env->light->norme < 5000) ? env->tmp.current->color.green \
		* env->tmp.power * (env->tmp.darkness) * \
		(1 - (env->light->norme / 5000)) : 0;
	color.blue = (env->light->norme < 5000) ? env->tmp.current->color.blue * \
		env->tmp.power * (env->tmp.darkness) * \
		(1 - (env->light->norme / 5000)) : 0;
	color = ft_option_col(env, color);
	color.red = (env->amb == 1) ? color.red * env->amb_coef : color.red;
	color.green = (env->amb == 1) ? color.green * env->amb_coef : color.green;
	color.blue = (env->amb == 1) ? color.blue * env->amb_coef : color.blue;
	env->tmp.current->color = tmp;
	return (color);
}
