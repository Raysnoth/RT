/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:19:13 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/10 10:32:33 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

static void	ft_freesrcs(char **s1, char **s2, int mod)
{
	if (mod == 1 || mod == 3)
		free(*s1);
	if (mod == 2 || mod == 3)
		free(*s2);
}

char		*ft_freestrjoin(char *s1, char *s2, int mod)
{
	char	*new;
	int		i;
	int		j;

	if (s1 && s2)
	{
		new = NULL;
		i = 0;
		j = 0;
		new = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + \
					ft_strlen((char *)s2) + 1));
		if (!new)
			return (NULL);
		while (s1[i])
			new[j++] = s1[i++];
		i = 0;
		while (s2[i])
			new[j++] = s2[i++];
		new[j] = '\0';
		ft_freesrcs(&s1, &s2, mod);
		return (new);
	}
	return (NULL);
}
