/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:08 by marnaud           #+#    #+#             */
/*   Updated: 2017/08/23 20:23:53 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_init_point(t_env *env, t_vect *point)
{
	point->x = env->tmp.ray_pos.x - env->tmp.current->pos.x;
	point->y = env->tmp.ray_pos.y - env->tmp.current->pos.y;
	point->z = env->tmp.ray_pos.z - env->tmp.current->pos.z;
	if (env->tmp.current->type == 2)
	{
		point->x = (env->tmp.ray_pos.x > env->tmp.current->pos.x) ? \
		env->tmp.ray_pos.x - env->tmp.current->pos.x : \
		env->tmp.current->pos.x - env->tmp.ray_pos.x;
		point->y = (env->tmp.ray_pos.y > env->tmp.current->pos.y) ? \
		env->tmp.ray_pos.y - env->tmp.current->pos.y :
		env->tmp.current->pos.y - env->tmp.ray_pos.y;
		point->z = (env->tmp.ray_pos.z > env->tmp.current->pos.z) ? \
		env->tmp.ray_pos.z - env->tmp.current->pos.z : \
		env->tmp.current->pos.z - env->tmp.ray_pos.z;
	}
	*point = (point->x != 1 && point->x != -1) ? \
		ft_vect_rot(*point, -env->tmp.current->angles.x, 3) : \
		ft_vect_rot(*point, -env->tmp.current->angles.x, 1);
	*point = ft_vect_rot(*point, -env->tmp.current->angles.y, 2);
	*point = ft_vect_rot(*point, -env->tmp.current->angles.z, 1);
}

static int	ft_get_s(t_env *env, SDL_Surface *texture, t_vect *point, \
		int action)
{
	if (action == 1)
	{
		if (point->x <= 0)
			point->x += texture->w * ceil(-point->x / texture->w);
		if (point->x > texture->w)
			point->x -= texture->w * floor(point->x / texture->w);
		return (point->x);
	}
	if (action == 2)
	{
		if (point->y < 0)
			return (floor(((point->x / (tan(env->tmp.current->angle) * \
					point->z) + 1) / 2) * (texture->w / 2)));
		else
			return (floor(((-point->x / (tan(env->tmp.current->angle) * \
					point->z) + 1) / 2) * (texture->w / 2)) + texture->w / 2);
	}
	else
		return (point->y < 0) ? (floor(((point->x / \
			env->tmp.current->radius + 1) / 2) * (texture->w / 2))) : \
			floor(((-point->x / env->tmp.current->radius + 1) / 2) * \
			(texture->w / 2)) + texture->w / 2;
}

static int	ft_get_t(t_env *env, SDL_Surface *texture, t_vect *point, \
		int action)
{
	if (action == 1)
	{
		if (point->y <= 0)
			point->y += texture->h * ceil(point->y / texture->h);
		if (point->y > texture->h)
			point->y -= texture->h * floor(point->y / texture->h);
		return (point->y);
	}
	if (action == 2)
	{
		if (env->tmp.current->type == 1)
			return (floor(((-point->z / env->tmp.current->radius + 1) / 2) * \
						texture->h));
		else
		{
			if (point->z < 0)
				point->z += texture->h * ceil(-point->z / texture->h);
			if (point->z > texture->h)
				point->z -= texture->h * floor(point->z / texture->h);
			return (point->z);
		}
	}
	return (point->y);
}

void		first_point(t_env *env, int *s, int *t, SDL_Surface *texture)
{
	t_vect		point;

	ft_init_point(env, &point);
	if (env->tmp.current->type == 2)
	{
		*s = ft_get_s(env, texture, &point, 1);
		*t = ft_get_t(env, texture, &point, 1);
	}
	else
	{
		if (env->tmp.current->type == 4)
			*s = ft_get_s(env, texture, &point, 2);
		else
			*s = ft_get_s(env, texture, &point, 3);
		*t = ft_get_t(env, texture, &point, 2);
	}
	if (*t > texture->h || *t < -texture->h)
		*t = (*t < 0) ? -texture->h : texture->h;
	if (*s > texture->w || *s < -texture->w)
		*s = (*s < 0) ? -texture->w : texture->w;
}

t_color		ft_texture(t_env *env)
{
	int			s;
	int			t;
	Uint8		tmp[3];
	t_color		color;
	SDL_Surface	*surf;

	surf = NULL;
	env->tmp.ray_pos = env->light->solution_point;
	if (env->tmp.current->tex == 1)
		surf = env->sdl.surf[0];
	else if (env->tmp.current->tex == 2)
		surf = env->sdl.surf[1];
	else if (env->tmp.current->tex == 3)
		surf = env->sdl.surf[2];
	else if (env->tmp.current->tex == 4)
		surf = env->sdl.surf[3];
	else if (env->tmp.current->tex == 5)
		surf = env->sdl.surf[4];
	first_point(env, &s, &t, surf);
	SDL_GetRGB(obtenir_pixel(surf, s, t), \
			surf->format, &tmp[0], &tmp[1], &tmp[2]);
	color.red = (int)tmp[0];
	color.green = (int)tmp[1];
	color.blue = (int)tmp[2];
	return (color);
}
