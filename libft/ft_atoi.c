/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3tard3d <r3tard3d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:17:18 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/01/26 15:44:36 by r3tard3d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		a;
	int		i;
	int		sign;

	a = 0;
	i = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_strlen(str) == 27 && sign == -1)
			return (0);
		if (ft_strlen(str) == 26 && sign == 1)
			return (-1);
		a = ((a * 10) + (str[i++] - 48));
	}
	return (a * sign);
}
