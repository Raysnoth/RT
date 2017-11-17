/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:30:02 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 14:10:31 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** verifier si toutes les valeurs sont correctement rentree
*/

static void	ft_cam_angles(t_env *env, int i)
{
	char	**sp;
	int		*tab;

	tab = ft_create_tab_verif();
	sp = env->parse.split;
	env->check.direction = 1;
	while (sp[i])
	{
		if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "x") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[0] = 1))
			env->cam.angles.x = (double)(ft_atoi(sp[i + 2] + 1));
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "y") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[1] = 1))
			env->cam.angles.y = (double)(ft_atoi(sp[i + 2] + 1));
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "z") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[2] = 1))
			env->cam.angles.z = (double)(ft_atoi(sp[i + 2] + 1));
		else if (ft_strequ(sp[i], "/>") && i == env->parse.tablen - 1)
			return (ft_verif_tab(env, tab, 1));
		else
			ft_error_check_file(env);
		i += 3;
	}
}

static void	ft_pos_cam(t_env *env, int i)
{
	char	**sp;
	int		*tab;

	tab = ft_create_tab_verif();
	sp = env->parse.split;
	env->check.position = 1;
	while (env->parse.split[i])
	{
		if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "x") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[0] = 1))
			env->cam.pos.x = (double)(ft_atoi(env->parse.split[i + 2] + 1));
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "y") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[1] = 1))
			env->cam.pos.y = (double)(ft_atoi(env->parse.split[i + 2] + 1));
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "z") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[2] = 1))
			env->cam.pos.z = (double)(ft_atoi(env->parse.split[i + 2] + 1));
		else if (!ft_strcmp(sp[i], "/>") && i == env->parse.tablen - 1)
			return (ft_verif_tab(env, tab, 1));
		else
			ft_error_check_file(env);
		i += 3;
	}
}

void		ft_fill_cam(t_env *env)
{
	char	**sp;

	sp = env->parse.split;
	if (env->parse.tablen != 1)
	{
		if (!ft_strcmp(sp[0], "<position"))
			ft_pos_cam(env, 1);
		else if (!ft_strcmp(sp[0], "<angles"))
			ft_cam_angles(env, 1);
		else
			ft_error_check_file(env);
	}
	else if (env->parse.tablen == 1)
	{
		if (!ft_strcmp(sp[0], "</camera>"))
		{
			if ((env->check.position == 0 || env->check.direction == 0))
				ft_error_check_file(env);
			env->parse.type = 0;
		}
		if (!ft_strcmp(sp[0], "<camera>"))
			ft_check_obj_types(env);
	}
	else
		ft_check_obj_types(env);
}
