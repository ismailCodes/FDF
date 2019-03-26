/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:12:50 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/03/04 19:28:39 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_rows(t_environement *env, t_point **c_tab,
					int n_lines, int n_cols)
{
	t_point	p;

	p.y = 0;
	while (p.y <= (n_lines - 1))
	{
		p.x = 0;
		while (p.x < n_cols)
		{
			if (p.x < n_cols - 1)
			{
				p.x = get_right(env, c_tab, p, n_cols - 1);
				draw_line(env);
			}
			else
				p.x++;
		}
		p.y++;
	}
}

void	draw_cols(t_environement *env, t_point **c_tab,
					int n_lines, int n_cols)
{
	t_point	p;

	p.x = 0;
	while (p.x <= (n_cols - 1))
	{
		p.y = 0;
		while (p.y < n_lines)
		{
			if (p.y < n_lines - 1)
			{
				p.y = get_down(env, c_tab, p, n_lines - 1);
				draw_line(env);
			}
			else
				p.y++;
		}
		p.x++;
	}
}

void	draw_grid(t_environement *env, t_point **c_tab,
					int n_lines, int n_cols)
{
	draw_rows(env, c_tab, n_lines, n_cols);
	draw_cols(env, c_tab, n_lines, n_cols);
}
