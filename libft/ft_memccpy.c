/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:56:42 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/18 10:44:48 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*source;
	unsigned char		*dest;
	unsigned char		d;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	d = (unsigned char)c;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == d)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
