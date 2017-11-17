/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:06:02 by gauffret          #+#    #+#             */
/*   Updated: 2017/08/23 10:06:03 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_parse_position(t_env *env, int i)
{
	char	**sp;
	int		*tab;

	tab = ft_create_tab_verif();
	sp = env->parse.split;
	env->check.position = 1;
	while (sp[i])
	{
		if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "x") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[0] = 1))
			env->tmp.pos.x = ft_atoi(sp[i + 2] + 1);
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "y") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[1] = 1))
			env->tmp.pos.y = ft_atoi(sp[i + 2] + 1);
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "z") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[2] = 1))
			env->tmp.pos.z = ft_atoi(sp[i + 2] + 1);
		else if (ft_strequ(sp[i], "/>") && i == env->parse.tablen - 1)
			return (ft_verif_tab(env, tab, 1));
		else
			ft_error_check_file(env);
		i += 3;
	}
}

void	ft_parse_angles(t_env *env, int i, int *tab)
{
	char	**sp;

	sp = env->parse.split;
	env->check.direction = 1;
	while (sp[i])
	{
		if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "x") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[0] = 1))
			env->tmp.angles.x = ft_atoi(sp[i + 2] + 1);
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "y") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[1] = 1))
			env->tmp.angles.y = ft_atoi(sp[i + 2] + 1);
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "z") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (tab[2] = 1))
			env->tmp.angles.z = ft_atoi(sp[i + 2] + 1);
		else if (env->parse.type_obj == PLANE && sp[i] && sp[i + 1] \
	&& sp[i + 2] && !ft_strcmp(sp[i], "h") && !ft_strcmp(sp[i + 1], "=") \
	&& ft_verif_num(sp[i + 2], env) && (tab[3] = 1))
			env->tmp.angles.h = ft_atoi(sp[i + 2] + 1);
		else if (ft_strequ(sp[i], "/>") && i == env->parse.tablen - 1)
			return (ft_verif_tab(env, tab, 2));
		else
			ft_error_check_file(env);
		i += 3;
	}
}

void	ft_parse_finished(t_env *env, int i)
{
	char	**sp;
	int		chk;

	chk = 0;
	sp = env->parse.split;
	env->tmp.finished = 1;
	while (sp[i])
	{
		if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "min") && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (chk = 1))
			env->tmp.fin[0] = ft_atoi(sp[i + 2] + 1);
		else if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "max") \
	&& !ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && (chk = 1))
			env->tmp.fin[1] = ft_atoi(sp[i + 2] + 1);
		else if (ft_strequ(sp[i], "/>") && i == env->parse.tablen - 1)
		{
			if (!chk)
				ft_error_check_file(env);
			return ;
		}
		else
			ft_error_check_file(env);
		i += 3;
	}
}

void	ft_parse_index(t_env *env, int i, int *tab)
{
	char	**sp;

	sp = env->parse.split;
	while (sp && sp[i])
	{
		if (sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "reflection") && \
		!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && \
		(tab[0] = 1))
			env->tmp.refle = ft_atoi(sp[i + 2] + 1);
		else if (sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "refraction") && \
		!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && \
		(tab[1] = 1))
			env->tmp.refra = ft_atoi(sp[i + 2] + 1);
		else if (sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i], "transparency") \
		&& !ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && \
		(tab[2] = 1))
			env->tmp.refra_trans = ft_atoi(sp[i + 2] + 1);
		else if (ft_strequ(sp[i], "/>") && i == env->parse.tablen - 1)
			return (ft_verif_tab(env, tab, 3));
		else
			ft_error_check_file(env);
		i += 3;
	}
}

void	ft_parse_attribute(t_env *env, int i)
{
	char	**sp;
	int		*tab;

	tab = ft_create_tab_verif();
	sp = env->parse.split;
	if (env->parse.type_obj == CONE && sp[i] && !ft_strcmp(sp[i], "angle") && \
	sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i + 1], "=") && \
	ft_verif_num(sp[i + 2], env) && sp[i + 3] && !ft_strcmp(sp[i + 3], "/>") \
	&& i + 3 == env->parse.tablen - 1 && (tab[1] = 1))
	{
		env->check.angle = 1;
		env->tmp.angle = ft_atoi(sp[i + 2] + 1);
	}
	else if ((env->parse.type_obj == SPHERE || env->parse.type_obj == CYL) \
	&& sp[i] && !ft_strcmp(sp[i], "radius") && sp[i + 1] && sp[i + 2] && \
	!ft_strcmp(sp[i + 1], "=") && ft_verif_num(sp[i + 2], env) && sp[i + 3] \
	&& !ft_strcmp(sp[i + 3], "/>") && (i + 3 == env->parse.tablen - 1) && \
	(tab[2] = 1))
	{
		env->check.radius = 1;
		env->tmp.radius = ft_atoi(env->parse.split[i + 2] + 1);
	}
	else
		ft_error_check_file(env);
	ft_verif_tab(env, tab, 4);
}
