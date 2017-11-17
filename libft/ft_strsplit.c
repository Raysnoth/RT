/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:52:27 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/16 16:42:00 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	ft_count_l(char const *str, int i, char c)
{
	int		j;

	j = i;
	while (str[j] != c && str[j])
		j++;
	return (j - i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = NULL;
	if (s && c)
	{
		i = -1;
		j = 0;
		if ((tab = (char **)malloc(sizeof(char *) * (ft_cw(s, c) + 1))) == NULL)
			return (NULL);
		while (++i < ft_cw(s, c))
		{
			k = 0;
			while (s[j] == c && s[j])
				j++;
			tab[i] = ft_strnew(ft_count_l(s, j, c));
			while (s[j] != c && s[j])
				tab[i][k++] = s[j++];
			tab[i][k] = '\0';
		}
		tab[i] = NULL;
	}
	return (tab);
}
