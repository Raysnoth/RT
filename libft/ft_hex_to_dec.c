/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:01:09 by ele-cren          #+#    #+#             */
/*   Updated: 2017/03/10 15:01:12 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_hex_to_dec(char *str)
{
	int		nb;
	int		res;
	int		i;
	int		j;

	res = 0;
	i = (str[1] == 'x') ? 2 : 0;
	j = (str[1] == 'x') ? ft_strlen(str) - 3 : ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] >= 'A' & str[i] <= 'F')
			nb = str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			nb = str[i] - 'a' + 10;
		else if (str[i] >= '0' && str[i] <= '9')
			nb = str[i] - '0';
		else
			return (0);
		res += nb * ft_pow(16, j);
		i++;
		j--;
	}
	return (res);
}
