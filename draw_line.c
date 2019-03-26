/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:57:23 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/03/15 21:59:54 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(int *img_data, int x, int y, t_environement *env)
{
	int		index;

	index = WIDTH * y + x;
	if (index >= 0
		&& index < WIDTH * IMGH
		&& x < WIDTH && y < IMGH
		&& x >= 0 && y >= 0)
		img_data[WIDTH * y + x] = env->color;
}

/*
** This fuction draws a line between two points using bresenham algorithm
*/

void	draw_line(t_environement *env)
{
	t_line var;

	var.point_x = env->x1;
	var.point_y = env->y1;
	var.diff_x = env->x2 - env->x1;
	var.diff_y = env->y2 - env->y1;
	var.inc_x = (var.diff_x > 0) ? 1 : -1;
	var.inc_y = (var.diff_y > 0) ? 1 : -1;
	var.diff_x = abs(var.diff_x);
	var.diff_y = abs(var.diff_y);
	fill_pixel(env->img.data, var.point_x, var.point_y, env);
	(var.diff_x > var.diff_y)
		? dx_sup(env, &var, env->img.data)
		: dx_inf(env, &var, env->img.data);
}
