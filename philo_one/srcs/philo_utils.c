/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:18:43 by user42            #+#    #+#             */
/*   Updated: 2021/01/06 20:06:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_bool	must_eat_has_been_reached(t_prg *prg)
{
	int i;

	i = 0;
	while (i < prg->n_philosophers)
	{
		if (prg->philos[i].actu_meal < prg->n_philo_must_eat)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
