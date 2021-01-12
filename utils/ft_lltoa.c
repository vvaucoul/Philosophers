/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:16:17 by user42            #+#    #+#             */
/*   Updated: 2021/01/09 20:16:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char			*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	if ((ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int64_t		n_lenght(int64_t n)
{
	int64_t nsize;

	nsize = 0;
	if (n > -9223372036854775807 && n < 0)
	{
		++nsize;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	else if (n == -9223372036854775807)
		return (11);
	while (n >= 1)
	{
		n /= 10;
		++nsize;
	}
	return (nsize);
}

static int64_t		is_min_int(int64_t n, char **str)
{
	if (n != -9223372036854775807)
		return (0);
	*str = ft_strdup("-9223372036854775807");
	return (1);
}

char				*ft_lltoa(int64_t n)
{
	int64_t				i;
	int64_t				size;
	char				*str;
	int64_t				isneg;

	size = n_lenght(n);
	if ((str = malloc(sizeof(char) * (n_lenght(n) + 1))) == NULL)
		return (NULL);
	if (is_min_int(n, &str) == 1)
		return (str);
	if ((isneg = ((n >= -9223372036854775807 && n < 0) ? 1 : 0)) == 1)
		n *= -1;
	i = (isneg ? 1 : 1);
	while (size - i >= 0)
	{
		str[size - i] = n % 10 + 48;
		n /= 10;
		++i;
	}
	if (isneg)
		str[0] = '-';
	str[size] = '\0';
	return (str);
}
