/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:55:13 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/18 12:53:37 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		if (n == 0)
			return (1);
		while ((s1[i] || s2[i]) && i < (n - 1))
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (s1[i] == s2[i])
			return (1);
	}
	return (0);
}
