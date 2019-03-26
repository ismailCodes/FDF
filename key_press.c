/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:17:17 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/03/15 19:35:27 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_map(t_environement *env)
{
	env->scalexy *= 1.2;
	env->scalez *= 1.2;
	mlx_destroy_image(env->mlx_ptr, env->img.ptr);
	env->img.ptr = mlx_new_image(env->mlx_ptr, WIDTH, IMGH);
	env->img.data = (int*)mlx_get_data_addr(env->img.ptr,
					&(env->img.bitspp), &(env->img.sizeln),
					&(env->img.endian));
	env->oblique
		? ft_center_oblique(env, env->max_rows, env->max_cols)
		: ft_center_iso(env, env->max_rows, env->max_cols);
	draw_grid(env, env->coord_tab, env->max_rows, env->max_cols);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
						env->img.ptr, 0, 0);
}

void	ft_reload_map(t_environement *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img.ptr);
	env->img.ptr = mlx_new_image(env->mlx_ptr, WIDTH, IMGH);
	env->img.data = (int*)mlx_get_data_addr(env->img.ptr,
					&(env->img.bitspp), &(env->img.sizeln),
					&(env->img.endian));
	ft_bzero(env->img.data, WIDTH * IMGH);
	draw_grid(env, env->coord_tab, env->max_rows, env->max_cols);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
						env->img.ptr, 0, 0);
}

void	ft_unzoom_map(t_environement *env)
{
	env->scalexy /= 1.2;
	env->scalez /= 1.2;
	mlx_destroy_image(env->mlx_ptr, env->img.ptr);
	env->img.ptr = mlx_new_image(env->mlx_ptr, WIDTH, IMGH);
	env->img.data = (int*)mlx_get_data_addr(env->img.ptr,
					&(env->img.bitspp), &(env->img.sizeln),
					&(env->img.endian));
	env->oblique
		? ft_center_oblique(env, env->max_rows, env->max_cols)
		: ft_center_iso(env, env->max_rows, env->max_cols);
	draw_grid(env, env->coord_tab, env->max_rows, env->max_cols);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
						env->img.ptr, 0, 0);
}

void	set_alpha_channel(t_environement *env)
{
	int		i;

	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	i = 0;
	while (i < WIDTH * IMGH)
	{
		if (env->img.data[i])
		{
			if ((env->img.data[i] & 0xFF000000) == 0xFF000000)
				env->img.data[i] &= 0x00FFFFFF;
			else
				env->img.data[i] += 0x11000000;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
						env->img.ptr, 0, 0);
}

int		key_press(int keycode, t_environement *env)
{
	if (keycode == 53)
		ft_exit_fdf(env);
	(keycode == 116) ? ft_zoom_map(env) : 0;
	(keycode == 121) ? ft_unzoom_map(env) : 0;
	(keycode == 49) ? set_alpha_channel(env) : 0;
	(keycode == 24) ? env->scalez++ : 0;
	(keycode == 27) ? env->scalez-- : 0;
	(keycode == 124) ? env->trans.x += 20 : 0;
	(keycode == 123) ? env->trans.x += -20 : 0;
	(keycode == 125) ? env->trans.y += 20 : 0;
	(keycode == 126) ? env->trans.y += -20 : 0;
	if (keycode == 48)
	{
		env->oblique ? (env->oblique = 0)
						: (env->oblique = 1);
		ft_reload_map(env);
		ft_unzoom_map(env);
		ft_zoom_map(env);
	}
	ft_reload_map(env);
	return (0);
}
