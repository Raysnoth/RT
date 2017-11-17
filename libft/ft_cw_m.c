/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cw_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:40:04 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/31 11:13:59 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_del(char c, char *del)
{
	int		i;

	i = 0;
	while (del[i])
	{
		if (del[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_cw_m(char *str, char *del)
{
	int		i;
	int		count;

	if (str && del)
	{
		count = 0;
		i = 0;
		while (str[i])
		{
			while (ft_is_del(str[i], del) && str[i])
				i++;
			if (str[i] != '\0')
				count++;
			while (!ft_is_del(str[i], del) && str[i])
				i++;
		}
		return (count);
	}
	return (0);
}
