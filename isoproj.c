/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoproj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:30:27 by mzahir            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:25 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_to_iso(t_point coords1, t_point coords2, t_environement *env)
{
	int previous_x;
	int previous_y;

	previous_x = coords1.x * env->scalexy;
	previous_y = coords1.y * env->scalexy;
	env->x1 = (previous_x - previous_y) * cos(0.523599) + env->trans.x;
	env->y1 = -(coords1.z * env->scalez)
				+ (previous_x + previous_y) * sin(0.523599)
				+ env->trans.y;
	if (coords1.z)
		env->y1 -= (env->trans.z * env->scalez);
	previous_x = coords2.x * env->scalexy;
	previous_y = coords2.y * env->scalexy;
	env->x2 = (previous_x - previous_y) * cos(0.523599) + env->trans.x;
	env->y2 = -(coords2.z * env->scalez)
				+ (previous_x + previous_y) * sin(0.523599)
				+ env->trans.y;
	if (coords2.z)
		env->y2 -= (env->trans.z * env->scalez);
}

void	ft_to_oblique(t_point coords1, t_point coords2, t_environement *env)
{
	int previous_x;
	int previous_y;

	previous_x = coords1.x * env->scalexy;
	previous_y = coords1.y * env->scalexy;
	env->x1 = previous_x + coords1.z * env->scalez / 2 * cos(0.785398)
				+ env->trans.x;
	env->y1 = previous_y + coords1.z * env->scalez / 2 * sin(0.785398)
			+ env->trans.y;
	previous_x = coords2.x * env->scalexy;
	previous_y = coords2.y * env->scalexy;
	env->x2 = previous_x + coords2.z * env->scalez / 2 * cos(0.785398)
				+ env->trans.x;
	env->y2 = previous_y + coords2.z * env->scalez / 2 * sin(0.785398)
				+ env->trans.y;
}
