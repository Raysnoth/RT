/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_dup3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:00:40 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 13:06:05 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_filters	dup_filters(t_filters filt)
{
	t_filters	new;

	new.bw[0] = filt.bw[0];
	new.bw[1] = filt.bw[1];
	new.bw[2] = filt.bw[2];
	new.mo[0] = filt.mo[0];
	new.mo[1] = filt.mo[1];
	new.mo[2] = filt.mo[2];
	new.neg = filt.neg;
	return (new);
}
