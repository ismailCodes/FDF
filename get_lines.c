/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:18:28 by r3tard3d          #+#    #+#             */
/*   Updated: 2019/03/01 19:13:59 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_lines(int fd, char **lines, int num_lines)
{
	int		i;
	char	**str;

	str = (char**)malloc(num_lines * sizeof(char*));
	i = 0;
	while (get_next_line(fd, lines) == 1)
	{
		str[i] = ft_strdup(*lines);
		free(*lines);
		i++;
	}
	return (str);
}
