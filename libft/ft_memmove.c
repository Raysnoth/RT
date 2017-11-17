/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:39:14 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/14 14:04:38 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

static void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = n - 1;
	while (i >= 0)
	{
		dest[i] = source[i];
		i--;
	}
	dst = (void *)dest;
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		ft_memcpy_rev(dst, src, len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
