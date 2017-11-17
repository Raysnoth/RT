/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:45:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 14:52:17 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	ft_scalar(t_vect vec1, t_vect vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vect	ft_vect_op(t_vect vec1, char c, t_vect vec2)
{
	t_vect	res;

	res.x = 0;
	res.y = 0;
	res.z = 0;
	if (c == '-')
	{
		res.x = vec1.x - vec2.x;
		res.y = vec1.y - vec2.y;
		res.z = vec1.z - vec2.z;
	}
	else if (c == '+')
	{
		res.x = vec1.x + vec2.x;
		res.y = vec1.y + vec2.y;
		res.z = vec1.z + vec2.z;
	}
	return (res);
}

t_vect	ft_vect_op2(double tmp, char c, t_vect vec)
{
	t_vect	res;

	res.x = 0;
	res.y = 0;
	res.z = 0;
	if (c == '*')
	{
		res.x = vec.x * tmp;
		res.y = vec.y * tmp;
		res.z = vec.z * tmp;
	}
	else if (c == '/')
	{
		res.x = vec.x / tmp;
		res.y = vec.y / tmp;
		res.z = vec.z / tmp;
	}
	return (res);
}

t_vect	ft_vect_rot(t_vect d, double angle, int axe)
{
	t_vect	r;

	r.x = 0;
	r.y = 0;
	r.z = 0;
	if (axe == 1)
	{
		r.x = cos(angle * (M_PI / 180)) * d.x - sin(angle * (M_PI / 180)) * d.y;
		r.y = sin(angle * (M_PI / 180)) * d.x + cos(angle * (M_PI / 180)) * d.y;
		r.z = d.z;
	}
	else if (axe == 2)
	{
		r.x = cos(angle * (M_PI / 180)) * d.x + sin(angle * (M_PI / 180)) * d.z;
		r.y = d.y;
		r.z = -sin(angle * (M_PI / 180)) * d.x + cos(angle * (M_PI / 180)) \
			* d.z;
	}
	else if (axe == 3)
	{
		r.x = d.x;
		r.y = cos(angle * (M_PI / 180)) * d.y - sin(angle * (M_PI / 180)) * d.z;
		r.z = sin(angle * (M_PI / 180)) * d.y + cos(angle * (M_PI / 180)) * d.z;
	}
	return (r);
}

t_vect	ft_vect_prod(t_vect vec1, t_vect vec2)
{
	t_vect	r;

	r.x = vec1.y * vec2.z - vec1.z * vec2.y;
	r.y = vec1.z * vec2.x - vec1.x * vec2.z;
	r.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (r);
}
