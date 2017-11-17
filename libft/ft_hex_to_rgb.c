/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 10:32:00 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/10 10:32:22 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static char	**ft_create_tab(char *color)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	k = 0;
	tab = NULL;
	if (ft_strlen(color) < 6 && ft_strlen(color) > 8)
		exit(1);
	if ((tab = (char **)malloc(sizeof(char *) * 4)) == NULL)
		exit(0);
	i = (color[1] == 'x') ? 2 : 0;
	while (color[i])
	{
		tab[k] = ft_strnew(2);
		j = -1;
		while (++j < 2)
			tab[k][j] = color[i++];
		k++;
	}
	return (tab);
}

t_rgb		ft_hex_to_rgb(char *color)
{
	char	**tab;
	t_rgb	rgb;

	tab = NULL;
	tab = ft_create_tab(color);
	rgb.r = (tab[0]) ? ft_hex_to_dec(tab[0]) : 0;
	free(tab[0]);
	rgb.g = (tab[1]) ? ft_hex_to_dec(tab[1]) : 0;
	free(tab[1]);
	rgb.b = (tab[2]) ? ft_hex_to_dec(tab[2]) : 0;
	free(tab[2]);
	free(tab);
	return (rgb);
}
