/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:05:27 by gauffret          #+#    #+#             */
/*   Updated: 2017/08/23 10:05:28 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		ft_verif_num(char *str, t_env *env)
{
	int		i;

	i = 1;
	if (str && str[0] && str[0] == '"')
		;
	else
		ft_error_check_file(env);
	if (str && str[i] && str[i] == '-')
		i++;
	while (str && str[i] && str[i + 1])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error_check_file(env);
		i++;
	}
	if (str && str[i] && str[i] == '"')
		;
	else
		ft_error_check_file(env);
	return (1);
}

int		ft_check_com(t_env *env)
{
	if (env->parse.nb_line == 1 && !ft_strcmp(env->parse.split[0], "<!--"))
	{
		env->parse.com = 1;
		ft_tabdel(&env->parse.split);
		ft_strdel(&env->parse.line);
		return (1);
	}
	else if (env->parse.com && \
			!ft_strcmp(env->parse.split[env->parse.tablen - 1], "-->"))
	{
		env->parse.com = 0;
		ft_tabdel(&env->parse.split);
		ft_strdel(&env->parse.line);
		return (1);
	}
	else if (env->parse.com)
	{
		ft_tabdel(&env->parse.split);
		ft_strdel(&env->parse.line);
		return (1);
	}
	return (0);
}

int		*ft_create_tab_verif(void)
{
	int		*tab;

	tab = NULL;
	tab = (int *)malloc(sizeof(int) * 4);
	if (!tab)
		ft_error();
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	return (tab);
}

void	ft_verif_tab(t_env *env, int *tab, int action)
{
	if (action == 1)
		if (!tab[0] || !tab[1] || !tab[2])
			ft_error_check_file(env);
	if (action == 2)
		if (!tab[0] || !tab[1] || !tab[2] || \
		(!tab[3] && env->parse.type_obj == PLANE))
			ft_error_check_file(env);
	if (action == 3)
		if ((tab[1] && !tab[2]) || (!tab[1] && tab[2]) || (tab[0] && \
		env->tmp.refle < 0) || (tab[0] && env->tmp.refle > 100) || \
		(tab[1] && env->tmp.refra < 0) || (tab[1] && env->tmp.refra > 7) \
		|| (tab[2] && env->tmp.refra_trans < 0) || \
		(tab[2] && env->tmp.refra_trans > 100))
			ft_error_check_file(env);
	if (action == 4)
	{
		if (env->parse.type_obj == CONE && (!tab[1] || \
		(tab[1] && env->tmp.angle <= 0) || (tab[1] && env->tmp.angle >= 180)))
			ft_error_check_file(env);
		if ((env->parse.type_obj == SPHERE || env->parse.type_obj == CYL) \
		&& (!tab[2] || (tab[2] && env->tmp.radius <= 0)))
			ft_error_check_file(env);
	}
	free(tab);
	tab = NULL;
}
