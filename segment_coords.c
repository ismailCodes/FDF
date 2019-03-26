/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:44:56 by r3tard3d          #+#    #+#             */
/*   Updated: 2019/03/06 20:47:49 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_right(t_environement *env, t_point **c_tab, t_point p, int max)
{
	int			next_j;
	t_point		coord1;
	t_point		coord2;

	coord1.x = c_tab[p.y][p.x].x;
	coord1.y = c_tab[p.y][p.x].y;
	coord1.z = c_tab[p.y][p.x].z;
	next_j = p.x;
	if (c_tab[p.y][p.x].z == c_tab[p.y][p.x + 1].z)
		while (next_j < max && c_tab[p.y][next_j].z == c_tab[p.y][next_j + 1].z)
			next_j++;
	else
		next_j++;
	coord2.x = c_tab[p.y][next_j].x;
	coord2.y = c_tab[p.y][next_j].y;
	coord2.z = c_tab[p.y][next_j].z;
	env->oblique
	? ft_to_oblique(coord1, coord2, env)
	: ft_to_iso(coord1, coord2, env);
	env->factocolor = (c_tab[p.y][p.x].z - c_tab[p.y][next_j].z ?
			1 / abs(c_tab[p.y][p.x].z - c_tab[p.y][next_j].z) : 0);
	(c_tab[p.y][p.x].z || c_tab[p.y][next_j].z)
	? (env->color = BLUE)
	: (env->color = WHITE);
	return (next_j);
}

int		get_down(t_environement *env, t_point **c_tab, t_point p, int max)
{
	int			next_i;
	t_point		coord1;
	t_point		coord2;

	coord1.x = c_tab[p.y][p.x].x;
	coord1.y = c_tab[p.y][p.x].y;
	coord1.z = c_tab[p.y][p.x].z;
	next_i = p.y;
	if (c_tab[p.y][p.x].z == c_tab[p.y + 1][p.x].z)
		while (next_i < max && c_tab[next_i][p.x].z == c_tab[next_i + 1][p.x].z)
			next_i++;
	else
		next_i++;
	coord2.x = c_tab[next_i][p.x].x;
	coord2.y = c_tab[next_i][p.x].y;
	coord2.z = c_tab[next_i][p.x].z;
	env->oblique
	? ft_to_oblique(coord1, coord2, env)
	: ft_to_iso(coord1, coord2, env);
	env->factocolor = (c_tab[p.y][p.x].z - c_tab[next_i][p.x].z ?
			1 / abs(c_tab[p.y][p.x].z - c_tab[next_i][p.x].z) : 0);
	(c_tab[p.y][p.x].z || c_tab[next_i][p.x].z)
	? (env->color = BLUE)
	: (env->color = WHITE);
	return (next_i);
}
