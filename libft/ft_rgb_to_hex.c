/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:00:59 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/23 15:58:01 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

char	*ft_rgb_to_hex(t_rgb rgb)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = NULL;
	str2 = NULL;
	str3 = NULL;
	str = ft_itoa_base(rgb.r, 16);
	if (str[0] >= '0' && str[0] <= '9' && ft_strlen(str) != 2)
		str = ft_freestrjoin("0", str, 2);
	str2 = ft_itoa_base(rgb.g, 16);
	if (str2[0] >= '0' && str2[0] <= '9' && ft_strlen(str2) != 2)
		str2 = ft_freestrjoin("0", str2, 2);
	str = ft_freestrjoin(str, str2, 3);
	str3 = ft_itoa_base(rgb.b, 16);
	if (str3[0] >= '0' && str3[0] <= '9' && ft_strlen(str3) != 2)
		str3 = ft_freestrjoin("0", str3, 2);
	str = ft_freestrjoin(str, str3, 3);
	return (str);
}
