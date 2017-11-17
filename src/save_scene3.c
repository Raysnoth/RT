/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 11:41:29 by gauffret          #+#    #+#             */
/*   Updated: 2017/08/23 11:41:31 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_event_save_add(char *str, FILE *file)
{
	fputs(str, file);
	ft_strdel(&str);
}

void	ft_event_save_vect(t_vect vect, FILE *file)
{
	ft_event_save_add(ft_itoa(vect.x), file);
	fputs("\" y = \"", file);
	ft_event_save_add(ft_itoa(vect.y), file);
	fputs("\" z = \"", file);
	ft_event_save_add(ft_itoa(vect.z), file);
}
