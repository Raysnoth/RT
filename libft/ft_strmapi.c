/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:29:06 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/10 16:54:55 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	if (s)
	{
		i = 0;
		new = (char *)malloc(sizeof(*new) * (ft_strlen(s) + 1));
		if (new == NULL)
			return (NULL);
		while (s[i])
		{
			new[i] = f(i, s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
