/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:13:20 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 21:09:30 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_check_objects3(t_env *env)
{
	if (env->parse.tablen != 1)
	{
		if (ft_strcmp(env->parse.split[0], "<attribute") && \
			ft_strcmp(env->parse.split[0], "<angles") && \
			ft_strcmp(env->parse.split[0], "<color") && \
			ft_strcmp(env->parse.split[0], "<finished") && \
			ft_strcmp(env->parse.split[0], "<index") && \
			ft_strcmp(env->parse.split[0], "<position"))
			ft_error_check_file(env);
	}
}

static void	ft_check_objects2(t_env *env)
{
	if (env->parse.tablen == 1)
	{
		if ((env->parse.type_obj) && ((!ft_strcmp(env->parse.split[0], \
		"</sphere>") && env->parse.type_obj == SPHERE) || \
		(!ft_strcmp(env->parse.split[0], "</plane>") && env->parse.type_obj \
		== PLANE) || (!ft_strcmp(env->parse.split[0], "</cylinder>") && \
		env->parse.type_obj == CYL) || (!ft_strcmp(env->parse.split[0], \
		"</cone>") && env->parse.type_obj == CONE) || \
		(!ft_strcmp(env->parse.split[0], "</parabole>") && \
		env->parse.type_obj == PARA) || (!ft_strcmp(env->parse.split[0], \
		"</ellipse>") && env->parse.type_obj == ELL)))
			ft_end_obj(env);
		else if ((!env->parse.type_obj) && (!ft_strcmp(env->parse.split[0], \
		"<sphere>") || !ft_strcmp(env->parse.split[0], "<plane>") \
		|| !ft_strcmp(env->parse.split[0], "<cylinder>") || \
		!ft_strcmp(env->parse.split[0], "<cone>") || \
		!ft_strcmp(env->parse.split[0], "<parabole>") || \
		!ft_strcmp(env->parse.split[0], "<ellipse>")))
			ft_check_obj_types(env);
		else if (!env->parse.type_obj && !ft_strcmp(env->parse.split[0], \
		"</objects>") && env->parse.tablen == 1)
			env->parse.type = 0;
		else
			ft_error_check_file(env);
	}
}

void		ft_check_objects(t_env *env)
{
	if (!ft_strcmp(env->parse.split[0], "<objects>"))
		ft_error_check_file(env);
	ft_check_objects2(env);
	ft_check_objects3(env);
	if (env->parse.type == OBJ && env->parse.tablen != 1 && \
		(env->parse.type_obj == SPHERE || env->parse.type_obj == PLANE \
		|| env->parse.type_obj == CYL || env->parse.type_obj == CONE || \
		env->parse.type_obj == PARA || env->parse.type_obj == ELL))
		ft_parse_objects(env);
}

void		ft_parse_objects(t_env *env)
{
	if (!ft_strcmp(env->parse.split[0], "<angles"))
		ft_parse_angles(env, 1, ft_create_tab_verif());
	else if (!ft_strcmp(env->parse.split[0], "<attribute"))
		ft_parse_attribute(env, 1);
	else if (!ft_strcmp(env->parse.split[0], "<color"))
		ft_parse_color(env, 1, ft_create_tab_verif());
	else if (!ft_strcmp(env->parse.split[0], "<finished"))
		ft_parse_finished(env, 1);
	else if (!ft_strcmp(env->parse.split[0], "<index"))
	{
		env->tmp.refle = 0;
		env->tmp.refra = 0;
		env->tmp.refra = 0;
		ft_parse_index(env, 1, ft_create_tab_verif());
	}
	else if (ft_strequ(env->parse.split[0], "<position") == 1)
		ft_parse_position(env, 1);
	else
		ft_error_check_file(env);
}

char		*ft_strtolower(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str && str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			res[i] = str[i] + 32;
		else
			res[i] = str[i];
		i++;
	}
	ft_strdel(&str);
	res[i] = '\0';
	return (res);
}
