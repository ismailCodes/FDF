/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:59:53 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/03/15 19:36:17 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define WIDTH	1200
# define HEIGHT	800
# define IMGH 700
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 16776960
# define CYAN 65535
# define MAGENTA 16711935
# define PI 3.14159

typedef struct		s_image
{
	void	*ptr;
	int		*data;
	int		bitspp;
	int		sizeln;
	int		endian;
}					t_image;

typedef struct		s_point
{
	int		x;
	int		y;
	int		z;
}					t_point;

typedef struct		s_environement
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color;
	int		factocolor;
	int		oblique;
	int		max_rows;
	int		max_cols;
	int		map_width;
	int		map_height;
	double	scalexy;
	double	scalez;
	t_image	img;
	t_point	trans;
	t_point	**coord_tab;
}					t_environement;

typedef struct		s_line
{
	int		diff_x;
	int		diff_y;
	int		inc_x;
	int		inc_y;
	int		point_x;
	int		point_y;

}					t_line;

typedef struct		s_rotate
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}					t_rotate;

void				fill_pixel(int *img_str, int x, int y, t_environement *env);
void				draw_line(t_environement *env);
void				dx_sup(t_environement *environement,
							t_line *var, int *img_str);
void				dx_inf(t_environement *environement,
							t_line *var, int *img_str);
int					key_press(int keycode, t_environement *environement);
void				init_line_var(t_environement *environement);
void				rotate(t_environement *e, int angle);
char				**get_lines(int fd, char **lines, int	num_lines);
char				***split_tab(char **lines, int num_lines);
int					get_num_lines(char *file);
int					**digitize(char **char_tab, int lines_nb);
int					get_line_width(char *line);
int					get_width(char **lines, int num_lines);
t_point				**fill_matrix(char ***char_tab, int num_lines, int num_col);
void				draw_grid(t_environement *env, t_point **coords_tab,
								int i, int j);
int					get_right(t_environement *env, t_point **c_tab,
								t_point p, int max);
int					get_down(t_environement *env, t_point **c_tab,
								t_point p, int max);
void				ft_transform_iso(t_point **coords, int lines, int numcols);
void				ft_to_iso(t_point coords1,
							t_point coords2, t_environement *env);
void				ft_to_oblique(t_point coords1,
							t_point coords2, t_environement *env);
void				ft_center_iso(t_environement *env,
									int num_lines, int num_col);
void				ft_center_oblique(t_environement *env,
										int num_lines, int num_col);
void				ft_scale_iso(t_environement *env,
									int num_col, int num_lines);
void				ft_exit_fdf(t_environement *env);

#endif
