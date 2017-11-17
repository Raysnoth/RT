/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:31:23 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/06 13:38:51 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_error_check_file(t_env *env)
{
	ft_putstr_fd("Error in file ", 2);
	ft_putstr_fd(env->parse.file, 2);
	ft_putstr_fd(" at line ", 2);
	ft_putnbr_fd(env->parse.nb_line, 2);
	ft_putstr_fd(".\n", 2);
	exit(1);
}

void	ft_error(void)
{
	ft_putendl("Error scene !");
	exit(1);
}

void	ft_error_file(void)
{
	perror("Error file");
	exit(1);
}

void	ft_error_sdl(void)
{
	ft_putstr("Error : ");
	ft_putendl(SDL_GetError());
	SDL_Quit();
	exit(1);
}
