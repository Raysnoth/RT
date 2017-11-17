/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:37:28 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/31 11:14:54 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	ft_is_del(char c, char *del)
{
	int		i;

	i = 0;
	while (del[i])
	{
		if (del[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_l(char *str, int i, char *del)
{
	int		j;

	j = i;
	while (!ft_is_del(str[j], del) && str[j])
		j++;
	return (j - i);
}

char		**ft_strsplit_m(char *s, char *del)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = NULL;
	if (!s || !del || (tab = (char **)malloc(sizeof(char *) \
					* (ft_cw_m(s, del) + 1))) == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_cw_m(s, del))
	{
		k = 0;
		while (ft_is_del(s[j], del) && s[j])
			j++;
		tab[i] = ft_strnew(ft_count_l(s, j, del));
		while (!ft_is_del(s[j], del) && s[j])
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
