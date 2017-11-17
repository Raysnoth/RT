/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:23:19 by ele-cren          #+#    #+#             */
/*   Updated: 2017/01/05 11:16:59 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char	*ft_strjoin(const char *s1, const char *s2)
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
		return (new);
	}
	return (NULL);
}
