/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:10:07 by user42            #+#    #+#             */
/*   Updated: 2021/01/09 20:17:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int64_t		get_current_time(void)
{
	struct timeval	tv;
	int64_t			time;

	if (gettimeofday(&tv, NULL))
		return (-1);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (time);
}
