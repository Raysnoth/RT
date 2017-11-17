/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:38:07 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/30 17:02:11 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_get_digits(char *str)
{
	char	*new;
	int		i;
	int		j;
	
	j = 0;
	i = 0;
	new = NULL;
	while (str[i] && (str[i] < '0' || str[i] > '9'))
		i++;
	j = i;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	if ((new = (char *)malloc(sizeof(char) * ((i - j) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && (str[i] < '0' || str[i] > '9'))
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}
