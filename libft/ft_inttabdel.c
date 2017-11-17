/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:24:02 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/18 16:45:00 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_inttabdel(int ***tab, int size)
{
	int		**new;
	int		i;

	new = NULL;
	i = -1;
	new = *tab;
	while (++i < size)
		free(new[i]);
	free(new);
	*tab = NULL;
}
