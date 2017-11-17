/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:49:37 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/09 14:30:02 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
