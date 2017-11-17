/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:04:58 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 12:05:00 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_check_obj_types(t_env *env)
{
	if (ft_strequ(env->parse.split[0], "<sphere>") == 1)
	{
		env->parse.type_obj = SPHERE;
		env->parse.objects++;
	}
	else if (ft_strequ(env->parse.split[0], "<plane>") == 1)
	{
		env->parse.type_obj = PLANE;
		env->parse.objects++;
	}
	else if (ft_strequ(env->parse.split[0], "<cylinder>") == 1)
	{
		env->parse.type_obj = CYL;
		env->parse.objects++;
	}
	ft_check_obj_types2(env);
}

void	ft_check_obj_types2(t_env *env)
{
	if (ft_strequ(env->parse.split[0], "<cone>") == 1)
	{
		env->parse.type_obj = CONE;
		env->parse.objects++;
	}
	else if (ft_strequ(env->parse.split[0], "<parabole>"))
	{
		env->parse.type_obj = PARA;
		env->parse.objects++;
	}
	else if (ft_strequ(env->parse.split[0], "<ellipse>"))
	{
		env->parse.type_obj = ELL;
		env->parse.objects++;
	}
}

int		ft_check_types(t_env *env)
{
	if (!ft_strcmp("<camera>", env->parse.split[0]) && !env->parse.type)
	{
		env->parse.type = CAM;
		env->parse.cam++;
		return (1);
	}
	else if (!ft_strcmp("<objects>", env->parse.split[0]) && !env->parse.type)
	{
		env->parse.type = OBJ;
		return (1);
	}
	else if (!ft_strcmp("<light>", env->parse.split[0]) && !env->parse.type)
	{
		env->parse.type = LIGHT;
		return (1);
	}
	else
		ft_error_check_file(env);
	return (0);
}

void	ft_check_light_types(t_env *env)
{
	if (!ft_strcmp(env->parse.split[0], "<basic>") && env->parse.tablen == 1)
	{
		env->parse.type_light = BASIC;
		env->parse.lights++;
	}
	else if (ft_strequ(env->parse.split[0], "<spotlight>") && \
			env->parse.tablen == 1)
	{
		env->parse.type_light = SPOT;
		env->parse.lights++;
	}
	else if ((ft_strequ(env->parse.split[0], "</basic>") || \
	ft_strequ(env->parse.split[0], "</spotlight>")) && env->parse.tablen == 1)
		env->parse.type_light = 0;
	else
		ft_error_check_file(env);
}
