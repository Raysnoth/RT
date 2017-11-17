/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:53:35 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/10 11:51:50 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != cc)
		i++;
	if (s[i] != cc)
		return (NULL);
	else
		return ((char *)s + i);
}
