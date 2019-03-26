/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dx_inf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:51:29 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/03/06 12:28:25 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	dx_inf(t_environement *environement, t_line *var, int *img_data)
{
	int		i;
	int		cumul;

	cumul = var->diff_y / 2;
	i = 1;
	while (i <= var->diff_y)
	{
		var->point_y += var->inc_y;
		cumul += var->diff_x;
		if (cumul >= var->diff_y)
		{
			cumul -= var->diff_y;
			var->point_x += var->inc_x;
		}
		i++;
		fill_pixel(img_data, var->point_x, var->point_y, environement);
	}
}
