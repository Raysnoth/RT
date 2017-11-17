/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:10:12 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/18 11:21:14 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	while (s[i])
		i++;
	while (i > 0 && s[i] != cc)
		i--;
	if (s[i] != cc)
		return (NULL);
	else
		return ((char *)s + i);
}
