/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 11:32:16 by gauffret          #+#    #+#             */
/*   Updated: 2017/08/23 11:32:17 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_choose_color2(t_env *env, char *str)
{
	if (!ft_strcmp(str, "\"red\"") || !ft_strcmp(str, "\"green\"") || \
		!ft_strcmp(str, "\"brown\"") || !ft_strcmp(str, "\"black\"") ||
		!ft_strcmp(str, "\"yellow\""))
		env->tmp.color.blue = 0;
	if (!ft_strcmp(str, "\"blue\"") || !ft_strcmp(str, "\"cyan\"") || \
		!ft_strcmp(str, "\"magenta\"") || !ft_strcmp(str, "\"white\""))
		env->tmp.color.blue = 255;
	if (!ft_strcmp(str, "\"pink\""))
		env->tmp.color.green = 105;
	if (!ft_strcmp(str, "\"pink\""))
		env->tmp.color.blue = 180;
	if (!ft_strcmp(str, "\"purple\""))
		env->tmp.color.red = 148;
	if (!ft_strcmp(str, "\"purple\""))
		env->tmp.color.blue = 211;
	if (!ft_strcmp(str, "\"brown\""))
		env->tmp.color.red = 88;
	if (!ft_strcmp(str, "\"brown\""))
		env->tmp.color.green = 41;
	if (!ft_strcmp(str, "\"grey\""))
	{
		env->tmp.color.red = 158;
		env->tmp.color.green = 158;
		env->tmp.color.blue = 158;
	}
}

void		ft_parse_tex(t_env *env, char *str, int *tab)
{
	if (env->parse.type == LIGHT)
		ft_error_check_file(env);
	if (!ft_strcmp(str, "\"checker\""))
		env->tmp.tex = CHECKER;
	else if (!ft_strcmp(str, "\"moon\""))
		env->tmp.tex = MOON;
	else if (!ft_strcmp(str, "\"sun\""))
		env->tmp.tex = SUN;
	else if (!ft_strcmp(str, "\"earth\""))
		env->tmp.tex = EARTH;
	else if (!ft_strcmp(str, "\"garden\""))
		env->tmp.tex = GARDEN;
	else if (!ft_strcmp(str, "\"none\""))
		env->tmp.tex = 0;
	else
		ft_error_check_file(env);
	if (ft_strcmp(str, "\"none\""))
	{
		tab[0] = 1;
		tab[1] = 1;
		tab[2] = 1;
	}
}

static void	ft_choose_color(t_env *env, char *str, int *tab)
{
	if (ft_strcmp(str, "\"red\"") && ft_strcmp(str, "\"blue\"") && \
		ft_strcmp(str, "\"green\"") && ft_strcmp(str, "\"pink\"") && \
		ft_strcmp(str, "\"purple\"") && ft_strcmp(str, "\"brown\"") && \
		ft_strcmp(str, "\"cyan\"") && ft_strcmp(str, "\"magenta\"") && \
		ft_strcmp(str, "\"black\"") && ft_strcmp(str, "\"white\"") && \
		ft_strcmp(str, "\"grey\"") && ft_strcmp(str, "\"yellow\""))
		ft_error_check_file(env);
	tab[0] = 1;
	tab[1] = 1;
	tab[2] = 1;
	if (!ft_strcmp(str, "\"red\"") || !ft_strcmp(str, "\"pink\"") || \
		!ft_strcmp(str, "\"magenta\"") || !ft_strcmp(str, "\"white\"") || \
		!ft_strcmp(str, "\"yellow\""))
		env->tmp.color.red = 255;
	if (!ft_strcmp(str, "\"green\"") || !ft_strcmp(str, "\"cyan\"") || \
		!ft_strcmp(str, "\"white\"") || !ft_strcmp(str, "\"yellow\""))
		env->tmp.color.green = 255;
	if (!ft_strcmp(str, "\"red\"") || !ft_strcmp(str, "\"blue\"") || \
		!ft_strcmp(str, "\"purple\"") || !ft_strcmp(str, "\"magenta\"") || \
		!ft_strcmp(str, "\"black\""))
		env->tmp.color.green = 0;
	if (!ft_strcmp(str, "\"blue\"") || !ft_strcmp(str, "\"green\"") || \
		!ft_strcmp(str, "\"cyan\"") || !ft_strcmp(str, "\"black\""))
		env->tmp.color.red = 0;
	ft_choose_color2(env, str);
}

void		ft_parse_color3(t_env *env, char *clr, char *nb, int *tab)
{
	if (!ft_strcmp(clr, "red") && ft_verif_num(nb, env) && (tab[0] = 1))
		env->tmp.color.red = ft_atoi(nb + 1);
	else if (!ft_strcmp(clr, "green") && ft_verif_num(nb, env) && (tab[1] = 1))
		env->tmp.color.green = ft_atoi(nb + 1);
	else if (!ft_strcmp(clr, "blue") && ft_verif_num(nb, env) && (tab[2] = 1))
		env->tmp.color.blue = ft_atoi(nb + 1);
	else if (!ft_strcmp(clr, "texture"))
		ft_parse_tex(env, nb, tab);
	else if (!ft_strcmp(clr, "color"))
		ft_choose_color(env, nb, tab);
	else
		ft_error_check_file(env);
	ft_strdel(&nb);
	ft_strdel(&clr);
}

void		ft_parse_color(t_env *env, int i, int *tab)
{
	char	**sp;

	sp = env->parse.split;
	env->check.color = 1;
	while (sp && sp[i])
	{
		if (sp[i] && sp[i + 1] && sp[i + 2] && !ft_strcmp(sp[i + 1], "="))
			ft_parse_color3(env, ft_strdup(sp[i]), ft_strdup(sp[i + 2]), tab);
		else if (!ft_strcmp(sp[i], "/>") && i == env->parse.tablen - 1)
			return (ft_verif_tab(env, tab, 1));
		else
			ft_error_check_file(env);
		i += 3;
	}
}
