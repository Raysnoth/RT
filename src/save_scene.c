/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 12:22:16 by gauffret          #+#    #+#             */
/*   Updated: 2017/08/23 14:33:18 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** modifier la touche de camera qui utilise controle
** modifier enum texture : deux texture avec le meme num
*/

static void	ft_event_comment(FILE *file)
{
	fputs("<!--\n\n", file);
	fputs("/!\\ Commentaires autorises seulement si il commence a", file);
	fputs("la premiere ligne /!\\\n\n", file);
	fputs("angle (cone attribute) between 0 and 180\n", file);
	fputs("radius (sphere and cylinder attribute) bigger than 0\n", file);
	fputs("reflection (index) between 0 and 100\n", file);
	fputs("refraction (index) between 0 and 7\n", file);
	fputs("transparency (index) between 0 and 100\n", file);
	fputs("\nTEXTURES : CHECKER, MOON, SUN, EARTH, GARDEN, NONE\n", file);
	fputs("\nOBJECTS : SPHERE, CYLINDER, ", file);
	fputs("PLANE, CONE, ELLIPSE, PARABOLE\n", file);
	fputs("\nCOLOR : RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, PINK, ", file);
	fputs("PURPLE, BROWN, BLACK, WHITE, GREY\n", file);
	fputs("\n-->\n\n", file);
}

static void	ft_event_save_cam(t_env *env, FILE *file)
{
	fputs("<camera>\n", file);
	fputs("\t<position x = \"", file);
	ft_event_save_vect(env->cam.pos, file);
	fputs("\" />\n", file);
	fputs("\t<angles x = \"", file);
	ft_event_save_vect(env->cam.angles, file);
	fputs("\" />\n", file);
	fputs("</camera>\n\n", file);
}

static void	ft_event_save_light2(FILE *file, t_light *tmp, char *type)
{
	while (tmp)
	{
		fputs("\t<", file);
		if (tmp->type == 1)
			type = ft_strdup("basic>\n");
		else if (tmp->type == 2)
			type = ft_strdup("spotlight>\n");
		fputs(type, file);
		fputs("\t\t<color red = \"", file);
		ft_event_save_add(ft_itoa(tmp->color.red), file);
		fputs("\" green = \"", file);
		ft_event_save_add(ft_itoa(tmp->color.green), file);
		fputs("\" blue = \"", file);
		ft_event_save_add(ft_itoa(tmp->color.blue), file);
		fputs("\" />\n\t\t<direction x = \"", file);
		ft_event_save_vect(tmp->dir, file);
		fputs("\" />\n\t\t<position x = \"", file);
		ft_event_save_vect(tmp->pos, file);
		fputs("\" />\n\t</", file);
		fputs(type, file);
		ft_strdel(&type);
		tmp = tmp->next;
	}
}

static void	ft_event_save_light(t_env *env, FILE *file, t_light *tmp, \
	char *type)
{
	fputs("<light>\n", file);
	if (env->amb)
	{
		fputs("\t<ambient coefficient = \"", file);
		fputs(ft_itoa(env->amb_coef), file);
		fputs("\" />\n", file);
	}
	else
		ft_event_save_light2(file, tmp, type);
	fputs("</light>\n", file);
}

void		ft_event_save(t_env *env)
{
	FILE	*file;
	char	*name;

	file = NULL;
	if ((env->sdl.event.key.keysym.sym == SDLK_e && \
		env->sdl.event.key.keysym.mod & SDLK_RCTRL) || \
		(env->sdl.event.key.keysym.sym == SDLK_e && \
		env->sdl.event.key.keysym.mod & SDLK_LCTRL))
	{
		mkdir("./scenes", 0775);
		name = ft_freestrjoin("./scenes/scene ", ft_create_date(), 2);
		name = ft_freestrjoin(name, ".xml", 1);
		file = fopen(name, "w");
		if (file)
		{
			ft_event_comment(file);
			ft_event_save_cam(env, file);
			ft_event_save_obj(file, NULL, env->obj);
			ft_event_save_light(env, file, env->light, NULL);
			fclose(file);
		}
		else
			ft_putstr_fd("Error save scene", 2);
	}
}
