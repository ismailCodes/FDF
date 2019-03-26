/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:27:36 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/03/15 21:59:11 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**fill_matrix(char ***char_tab, int num_lines, int num_col)
{
	t_point		**point;
	int			rows;
	int			cols;

	rows = 0;
	point = (t_point**)malloc(num_lines * sizeof(t_point*));
	while (rows < num_lines)
	{
		cols = 0;
		point[rows] = (t_point*)malloc(num_col * sizeof(t_point));
		while (cols < num_col)
		{
			point[rows][cols].y = rows;
			point[rows][cols].x = cols;
			point[rows][cols].z = ft_atoi(char_tab[rows][cols]);
			cols++;
		}
		rows++;
	}
	return (point);
}

void	ft_exit_fdf(t_environement *env)
{
	int		i;

	i = 0;
	while (i < env->max_rows)
		free(env->coord_tab[i++]);
	free(env->coord_tab);
	mlx_destroy_image(env->mlx_ptr, env->img.ptr);
	exit(0);
}
