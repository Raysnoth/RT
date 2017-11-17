/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:50:20 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/27 14:57:44 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_rgb_to_dec(t_rgb rgb)
{
	int		a;
	int		b;
	int		res;

	a = rgb.r / 16;
	b = rgb.r - (a * 16);
	res = a * ft_pow(16, 5) + b * ft_pow(16, 4);
	a = rgb.g / 16;
	b = rgb.g - (a * 16);
	res += a * ft_pow(16, 3) + b * ft_pow(16, 2);
	a = rgb.b / 16;
	b = rgb.b - (a * 16);
	res += a * ft_pow(16, 1) + b * ft_pow(16, 0);
	return (res);
}
