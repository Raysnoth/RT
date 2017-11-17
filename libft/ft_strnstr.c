/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:02:15 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/09 12:09:24 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = i;
		k = 0;
		while (big[j] == little[k] && j < len)
		{
			j++;
			k++;
			if (little[k] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
