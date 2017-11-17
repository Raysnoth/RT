/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 11:28:06 by gauffret          #+#    #+#             */
/*   Updated: 2017/07/27 11:56:17 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static char	*ft_verif_len_date(char *str)
{
	if (ft_strlen(str) == 1)
		str = ft_freestrjoin("0", str, 2);
	return (str);
}

char		*ft_create_date(void)
{
	time_t		tim;
	struct tm	*var_time;
	char		*date;
	char		*tmp;

	time(&tim);
	var_time = localtime(&tim);
	date = ft_freestrjoin(ft_itoa(var_time->tm_year + 1900), "-", 1);
	tmp = ft_verif_len_date(ft_itoa(var_time->tm_mon + 1));
	date = ft_freestrjoin(date, tmp, 3);
	date = ft_freestrjoin(date, "-", 1);
	tmp = ft_verif_len_date(ft_itoa(var_time->tm_mday));
	date = ft_freestrjoin(date, tmp, 3);
	date = ft_freestrjoin(date, " at ", 1);
	tmp = ft_verif_len_date(ft_itoa(var_time->tm_hour));
	date = ft_freestrjoin(date, tmp, 3);
	date = ft_freestrjoin(date, ".", 1);
	tmp = ft_verif_len_date(ft_itoa(var_time->tm_min));
	date = ft_freestrjoin(date, tmp, 3);
	date = ft_freestrjoin(date, ".", 1);
	tmp = ft_verif_len_date(ft_itoa(var_time->tm_sec));
	date = ft_freestrjoin(date, tmp, 3);
	return (date);
}
