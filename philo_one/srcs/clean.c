/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:08:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 12:37:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** Free all
** Le free de free philos ne fonctionne pas sur mac...
*/

int		free_prg(t_prg *prg)
{
	int i;

	if (prg)
	{
		i = 0;
		if (prg->forks)
		{
			while (i < prg->n_philosophers)
				pthread_mutex_destroy(&prg->forks[i++]);
			free(prg->forks);
		}
		if (prg->philos)
			free(prg->philos);
		pthread_mutex_destroy(&prg->info.philo_state);
		pthread_mutex_destroy(&prg->info.write_info);
		pthread_mutex_destroy(&prg->info.m_meal);
	}
	return (0);
}
