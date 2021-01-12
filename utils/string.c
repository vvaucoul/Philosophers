/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:13:27 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 17:30:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		ft_putstr_fd(char *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], 1);
			++i;
		}
	}
}

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int			ft_strlen(const char *s)
{
	long	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int			ft_isnum(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 48 && s[i] <= 57)
			++i;
		else
			return (1);
	}
	return (0);
}
