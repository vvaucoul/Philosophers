/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:18:43 by user42            #+#    #+#             */
/*   Updated: 2021/01/11 14:33:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_bool		must_eat_has_been_reached(t_prg *prg)
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

t_bool		philo_eat_is_zero(t_prg *prg)
{
	if (prg->n_philo_must_eat == 0)
	{
		prg->no_more_meal = TRUE;
		sem_post(prg->info.global);
		sem_post(prg->info.philo_state);
		usleep(DELAY_TO_PHILOSOPHERS + 50);
		display_end_message(prg, MSG_END);
		return (TRUE);
	}
	return (FALSE);
}
