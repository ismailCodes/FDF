/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalencenter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:49:25 by mzahir            #+#    #+#             */
/*   Updated: 2019/03/15 17:42:23 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center_iso(t_environement *env, int num_lines, int num_col)
{
	env->trans.x = (num_lines - 1) * env->scalexy * cos(0.523599);
	env->trans.x += WIDTH / 2 -
		(sqrt(pow(num_lines - 1, 2) + pow(num_col - 1, 2))
		/ cos(0.523599) * env->scalexy / 2);
	env->trans.y = (IMGH / 2)
				- ((num_lines - 1 + num_col - 1)
				* env->scalexy
				* sin(0.523599) / 2);
}

void	ft_scale_iso(t_environement *env, int num_col, int num_lines)
{
	env->max_rows = num_lines;
	env->max_cols = num_col;
	env->oblique = 0;
	env->scalexy = 30;
	env->scalez = 1.5;
	while (num_col * env->scalexy * cos(0.523599) > WIDTH
			|| (num_lines + num_col) * env->scalexy * sin(0.523599) > IMGH)
		env->scalexy /= 2;
	ft_center_iso(env, num_lines, num_col);
}

void	ft_center_oblique(t_environement *env, int num_lines, int num_col)
{
	env->trans.x = WIDTH / 2 - (num_col - 1) * env->scalexy / 2;
	env->trans.y = IMGH / 2 - (num_lines - 1) * env->scalexy / 2;
}

void	ft_scale_oblique(t_environement *env, int num_col, int num_lines)
{
	env->scalexy = 30;
	env->scalez = 1.5;
	while (num_col * env->scalexy > WIDTH
			|| num_lines * env->scalexy > IMGH)
		env->scalexy /= 2;
	ft_center_oblique(env, num_lines, num_col);
}
