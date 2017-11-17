/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:06:40 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 15:07:02 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_help_parse(t_env *env, char *av, int action)
{
	if (action == 1)
	{
		ft_init_env(env);
		ft_init_tmp(env);
		if ((env->parse.fd = open(av, O_RDONLY)) == -1)
			ft_error_file();
		env->parse.file = ft_strdup(av);
	}
	if (action == 2)
	{
		ft_strdel(&env->parse.line);
		if (env->parse.cam == 0)
			ft_error_check_file(env);
		if (close(env->parse.fd) == -1)
			ft_error_file();
	}
}

static void	ft_test_types(t_env *env)
{
	if (env->parse.type == CAM)
		ft_fill_cam(env);
	else if (env->parse.type == OBJ)
		ft_check_objects(env);
	else if (env->parse.type == LIGHT)
		ft_check_lights(env);
	else if (env->parse.tablen != 0)
		ft_error_check_file(env);
}

void		ft_parse(t_env *env, char *av)
{
	ft_help_parse(env, av, 1);
	while ((get_next_line(env->parse.fd, &env->parse.line)) == 1)
	{
		env->parse.line = ft_strtolower(env->parse.line);
		env->parse.nb_line++;
		env->parse.split = ft_strsplit_m(env->parse.line, " \t");
		env->parse.tablen = ft_tablen(env->parse.split);
		if (env->parse.tablen == 0 || ft_check_com(env))
		{
			ft_tabdel(&env->parse.split);
			ft_strdel(&env->parse.line);
			continue ;
		}
		if (env->parse.type == 0)
			if (ft_check_types(env))
			{
				ft_tabdel(&env->parse.split);
				ft_strdel(&env->parse.line);
				continue ;
			}
		ft_test_types(env);
		ft_tabdel(&env->parse.split);
		ft_strdel(&env->parse.line);
	}
	ft_help_parse(env, av, 2);
}
