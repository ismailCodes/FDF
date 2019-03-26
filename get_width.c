/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:35:03 by r3tard3d          #+#    #+#             */
/*   Updated: 2019/03/01 19:12:38 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_width(char **lines, int num_lines)
{
	int		i;
	int		num_col0;

	i = 1;
	num_col0 = get_line_width(lines[0]);
	while (i < num_lines)
	{
		if (num_col0 > get_line_width(lines[i]))
		{
			printf("FILE IS NOT VALID");
			exit(1);
		}
		i++;
	}
	return (num_col0);
}
