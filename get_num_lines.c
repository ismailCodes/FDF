/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:44:03 by r3tard3d          #+#    #+#             */
/*   Updated: 2019/03/01 19:14:36 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_num_lines(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open((file), O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}
