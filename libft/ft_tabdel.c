/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:52:59 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/16 15:49:33 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_tabdel(char ***tab)
{
	char	**new;
	int		i;

	new = *tab;
	if (new != NULL)
	{
		i = 0;
		while (new[i])
			ft_strdel(&(new[i++]));
		free(new);
		*tab = NULL;
	}
}
