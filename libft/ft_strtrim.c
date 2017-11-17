/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:42:53 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/14 11:43:41 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

static char	*ft_strtrim_an(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	j = ((int)ft_strlen(s) - 1);
	if (i > j)
		j += 2;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	str = ft_strnew((j - i) + 1);
	if (!str)
		return (NULL);
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	if (s)
		return (ft_strtrim_an(s));
	return (NULL);
}
