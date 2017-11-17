/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:41:35 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/26 14:18:20 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_dst;
	size_t	size_src;

	i = 0;
	j = 0;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size_dst < size)
		return (size_dst + size_src);
	return (size + size_src);
}
