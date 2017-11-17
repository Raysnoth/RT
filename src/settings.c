/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 12:54:04 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 12:39:27 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_settings(t_env *env)
{
	void	(*tab[8])(t_env *);

	tab[0] = ft_interface;
	tab[1] = ft_s_objects;
	tab[2] = ft_attributes;
	tab[3] = ft_pos_tab;
	tab[4] = ft_dir_tab;
	tab[5] = ft_col_tab;
	tab[6] = ft_base_tab;
	tab[7] = ft_eff_tab;
	tab[env->set.tab](env);
}
