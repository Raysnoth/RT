/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 10:29:53 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/27 14:56:15 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_itoaneg(int *neg, int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		i;

	str = NULL;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_nbrlen(n) + 1;
	ft_itoaneg(&neg, &n);
	i += neg;
	if ((str = ft_strnew(i - 1)) == NULL)
		return (NULL);
	--i;
	while (i--)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	if (neg != 0)
		str[0] = '-';
	return (str);
}
