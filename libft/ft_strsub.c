/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:39:18 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/10 16:53:28 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (s)
	{
		i = 0;
		new = (char *)malloc(sizeof(*new) * (len + 1));
		if (new == NULL)
			return (NULL);
		while (len > 0)
		{
			new[i] = s[start];
			i++;
			start++;
			len--;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
