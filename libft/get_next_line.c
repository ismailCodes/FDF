/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahir <mzahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:47:00 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/02/28 12:12:56 by mzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char		*temp[256];
	char			buff[BUFF_SIZE + 1];
	int				rd;
	int				i;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (temp[fd] == NULL)
		temp[fd] = ft_strnew(0);
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buff);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	i = 0;
	while (temp[fd][i] != '\0' && temp[fd][i] != '\n')
		i++;
	*line = ft_strsub(temp[fd], 0, i);
	if (!ft_strlen(temp[fd]) && rd == 0)
		return (0);
	temp[fd] = ft_strdup(temp[fd] + i + 1);
	return (1);
}
