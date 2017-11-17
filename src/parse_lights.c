/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:00:09 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 18:11:20 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_ambient_light(t_env *env)
{
	char	**sp;

	sp = env->parse.split;
	if (sp && sp[0] && sp[1] && sp[2] && sp[3] && sp[4] && !ft_strcmp(sp[0], \
			"<ambient") && !ft_strcmp(sp[1], "coefficient") && \
			!ft_strcmp(sp[2], "=") && !ft_strcmp(sp[4], "/>") && \
			ft_verif_num(sp[3], env))
	{
		env->amb_coef = ft_atoi(sp[3] + 1);
		if (env->amb_coef < 1 || env->amb_coef > 10)
			ft_error_check_file(env);
		env->amb_coef /= 10;
	}
	else
		ft_error_check_file(env);
}

void	ft_check_lights2(t_env *env)
{
	if (env->parse.type == LIGHT && env->parse.tablen != 1 && \
		(env->parse.type_light == BASIC || env->parse.type_light == SPOT))
		ft_parse_lights(env);
}

void	ft_check_lights(t_env *env)
{
	char	**sp;

	sp = env->parse.split;
	if (!ft_strcmp(sp[0], "<light>"))
		ft_error_check_file(env);
	if (env->parse.tablen == 1)
	{
		if ((!ft_strcmp(sp[0], "</basic>") && env->parse.type_light == BASIC) \
		|| (!ft_strcmp(sp[0], "</spotlight>") && env->parse.type_light == SPOT))
			ft_end_lights(env);
		else if (!ft_strcmp(sp[0], "<basic>") || !ft_strcmp(sp[0], \
		"<spotlight>"))
			ft_check_light_types(env);
		else if (!env->parse.type_obj && !ft_strcmp(sp[0], "</light>") && \
		env->parse.tablen == 1)
			env->parse.type = 0;
		else
			ft_error_check_file(env);
	}
	else if (env->parse.tablen != 1 && !ft_strcmp(sp[0], "<ambient"))
		ft_ambient_light(env);
	else if (env->parse.tablen != 1 && ft_strcmp(sp[0], "<position") && \
	ft_strcmp(sp[0], "<direction") && ft_strcmp(sp[0], "<color"))
		ft_error_check_file(env);
	ft_check_lights2(env);
}

void	ft_parse_lights(t_env *env)
{
	if (!ft_strcmp(env->parse.split[0], "<direction"))
		ft_parse_angles(env, 1, ft_create_tab_verif());
	else if (!ft_strcmp(env->parse.split[0], "<position"))
		ft_parse_position(env, 1);
	else if (!ft_strcmp(env->parse.split[0], "<color"))
		ft_parse_color(env, 1, ft_create_tab_verif());
	else
		ft_error_check_file(env);
}
