/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:52:40 by r3tard3d          #+#    #+#             */
/*   Updated: 2019/03/15 19:28:05 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***split_tab(char **lines, int lines_nb)
{
	int		i;
	char	***char_tab;

	i = 0;
	char_tab = (char***)malloc(lines_nb * sizeof(char**));
	while (i < lines_nb)
	{
		char_tab[i] = ft_strsplit(lines[i], ' ');
		free(lines[i]);
		i++;
	}
	free(lines);
	return (char_tab);
}
