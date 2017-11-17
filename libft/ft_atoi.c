/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:26:42 by ele-cren          #+#    #+#             */
/*   Updated: 2017/01/18 13:05:20 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 1;
	res = 0;
	while (ft_isescape(str[i]) && str[i] != '\0')
		i++;
	while ((str[i] == 45 || str[i] == 43) && str[i + 1] != 45 && str[i + 1] \
			!= 43)
	{
		if (str[i] == 45)
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return (res * j);
}
