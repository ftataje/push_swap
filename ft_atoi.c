/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:43:43 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/20 11:08:48 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_atoi_check(const char *str, int *error)
{
	int		sign;
	int		i;
	long	num;

	sign = 1;
	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	if (!str[i])
		*error = 1;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			*error = 1;
		num = num * 10 + (str[i++] - 48);
	}
	if ((num * sign) < INT_MIN || (num * sign) > INT_MAX)
		*error = 1;
	return (num * sign);
}
