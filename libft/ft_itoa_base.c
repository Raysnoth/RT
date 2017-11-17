/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:47:38 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/27 15:13:29 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

static int		ft_conv_to_hex(int value)
{
	if (value >= 10)
		return (value - 10 + 'A');
	else
		return (value + '0');
}

static int		ft_nblen(int value, int base)
{
	int		i;

	i = 0;
	while (value >= base)
	{
		value /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;
	int		tmp;

	str = NULL;
	if (base == 10)
		return (ft_itoa(value));
	if (base < 2 && base > 16)
		return (NULL);
	if (value < 0)
		return (NULL);
	i = ft_nblen(value, base);
	if ((str = (char *)malloc(sizeof(char) * (i + 2))) == NULL)
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i--] = ft_conv_to_hex(tmp);
		value /= base;
	}
	return (str);
}
