/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:46:33 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/23 20:20:11 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_ev_eff(t_env *env)
{
	ft_ev_eff_rlb(env);
	ft_ev_eff_du(env);
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
		ft_ev_eff_return1(env);
}

void	ft_ev_base(t_env *env)
{
	ft_ev_base_rlb(env);
	ft_ev_base_down(env);
	ft_ev_base_up(env);
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
		ft_ev_base_return1(env);
}
