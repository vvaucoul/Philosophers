/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:10:07 by user42            #+#    #+#             */
/*   Updated: 2021/01/09 20:15:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static long	ft_isdigit(long c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static long	skipuselesschar(const char *str)
{
	long	i;

	i = 0;
	while (str[i] == '\t'
	|| str[i] == '\n'
	|| str[i] == '\v'
	|| str[i] == '\r'
	|| str[i] == '\f'
	|| str[i] == ' ')
		++i;
	return (i);
}

long		ft_atol(const char *str)
{
	long		result;
	long		isneg;
	long		i;

	result = 0;
	i = skipuselesschar(str);
	isneg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		isneg = (str[i] == '-' ? 1 : 0);
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		++i;
	}
	return (isneg == 1 ? result *= -1 : result);
}
