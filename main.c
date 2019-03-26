/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:04:12 by mzahir            #+#    #+#             */
/*   Updated: 2019/03/15 18:17:28 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**get_coords(char *filename, int *num_lines, int *num_col)
{
	t_point			**coord_tab;
	int				fd;
	char			***char_tab;
	char			*line;
	char			**str;

	*num_lines = get_num_lines(filename);
	fd = open(filename, O_RDONLY);
	str = get_lines(fd, &line, *num_lines);
	*num_col = get_width(str, *num_lines);
	char_tab = split_tab(str, *num_lines);
	coord_tab = fill_matrix(char_tab, *num_lines, *num_col);
	return (coord_tab);
}

void	ft_put_menu(t_environement env)
{
	char	*menu1;
	char	*menu2;

	menu1 = "INSTRUCTIONS:  |Arrow keys| move  \
			|page up| zoom in  |page down| zoom out  |tab| change projection";
	menu2 = "|-| decrease altitude  |+| increase altitude  |esc| Quit";
	mlx_string_put(env.mlx_ptr, env.win_ptr, 20, HEIGHT - 80,
		0xFFFFFF, menu1);
	mlx_string_put(env.mlx_ptr, env.win_ptr, 20, HEIGHT - 50,
		0xFFFFFF, menu2);
}

int		main(int argc, char **argv)
{
	t_environement	env;
	int				num_lines;
	int				num_col;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf map_filename");
		return (0);
	}
	env.coord_tab = get_coords(argv[1], &num_lines, &num_col);
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WIDTH,
									HEIGHT, "test_window");
	env.img.ptr = mlx_new_image(env.mlx_ptr, WIDTH, IMGH);
	env.img.data = (int*)mlx_get_data_addr(env.img.ptr, &(env.img.bitspp),
									&(env.img.sizeln), &(env.img.endian));
	ft_bzero(env.img.data, WIDTH * IMGH);
	ft_scale_iso(&env, num_col, num_lines);
	draw_grid(&env, env.coord_tab, num_lines, num_col);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr,
							env.img.ptr, 0, 0);
	ft_put_menu(env);
	mlx_hook(env.win_ptr, 2, 0, key_press, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
