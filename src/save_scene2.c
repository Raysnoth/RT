/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 11:39:13 by gauffret          #+#    #+#             */
/*   Updated: 2017/08/23 11:39:15 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static char	*ft_event_save_type(int type)
{
	char	*str;

	str = NULL;
	if (type == 1)
		str = ft_strdup("sphere>\n");
	else if (type == 2)
		str = ft_strdup("plane>\n");
	else if (type == 3)
		str = ft_strdup("cylinder>\n");
	else if (type == 4)
		str = ft_strdup("cone>\n");
	return (str);
}

static void	ft_event_save_obj2(FILE *file, t_obj *tmp)
{
	if (tmp->type == 2 || tmp->type == 3 || tmp->type == 4)
	{
		fputs("\t\t<angles x = \"", file);
		ft_event_save_vect(tmp->angles, file);
		if (tmp->type == 2)
			fputs("\" h = \"", file);
		if (tmp->type == 2)
			ft_event_save_add(ft_itoa(tmp->angles.h), file);
		fputs("\" />\n", file);
	}
	if (tmp->type != 2)
	{
		if (tmp->type == 4)
		{
			fputs("\t\t<attribute angle = \"", file);
			ft_event_save_add(ft_itoa(tmp->angle), file);
			fputs("\" />\n", file);
		}
		if (tmp->type == 3 || tmp->type == 1)
		{
			fputs("\t\t<attribute radius = \"", file);
			ft_event_save_add(ft_itoa(tmp->radius), file);
			fputs("\" />\n", file);
		}
	}
}

static void	ft_event_save_obj3(FILE *file, t_obj *tmp)
{
	fputs("\t\t<color red = \"", file);
	ft_event_save_add(ft_itoa(tmp->color.red), file);
	fputs("\" green = \"", file);
	ft_event_save_add(ft_itoa(tmp->color.green), file);
	fputs("\" blue = \"", file);
	ft_event_save_add(ft_itoa(tmp->color.blue), file);
	if (tmp->tex == 0)
		fputs("\" texture = \"none\" />\n", file);
	if (tmp->tex == 1)
		fputs("\" texture = \"checker\" />\n", file);
	if (tmp->tex == 2)
		fputs("\" texture = \"moon\" />\n", file);
	if (tmp->tex == 3)
		fputs("\" texture = \"sun\" />\n", file);
	if (tmp->tex == 4)
		fputs("\" texture = \"earth\" />\n", file);
	if (tmp->tex == 5)
		fputs("\" texture = \"garden\" />\n", file);
}

static void	ft_event_save_obj4(FILE *file, char *type, t_obj *tmp)
{
	if (tmp->type == 3 && tmp->finished)
	{
		fputs("\t\t<finished min = \"", file);
		ft_event_save_add(ft_itoa(tmp->fin[0]), file);
		fputs("\" max = \"", file);
		ft_event_save_add(ft_itoa(tmp->fin[1]), file);
		fputs("\" />\n", file);
	}
	fputs("\t\t<index reflection = \"", file);
	ft_event_save_add(ft_itoa(tmp->refle), file);
	fputs("\" refraction = \"", file);
	ft_event_save_add(ft_itoa(tmp->refra), file);
	fputs("\" transparency = \"", file);
	ft_event_save_add(ft_itoa(tmp->refra_trans), file);
	fputs("\" />\n", file);
	if (tmp->type == 1 || tmp->type == 3 || tmp->type == 4)
	{
		fputs("\t\t<position x = \"", file);
		ft_event_save_vect(tmp->pos, file);
		fputs("\" />\n", file);
	}
	fputs("\t</", file);
	fputs(type, file);
	ft_strdel(&type);
}

void		ft_event_save_obj(FILE *file, char *type, t_obj *tmp)
{
	fputs("<objects>\n", file);
	while (tmp)
	{
		type = ft_event_save_type(tmp->type);
		fputs("\t<", file);
		fputs(type, file);
		ft_event_save_obj2(file, tmp);
		ft_event_save_obj3(file, tmp);
		ft_event_save_obj4(file, type, tmp);
		tmp = tmp->next;
	}
	fputs("</objects>\n\n", file);
}
