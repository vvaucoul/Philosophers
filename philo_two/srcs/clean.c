/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:08:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 15:13:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** Free all
** Le free de free philos ne fonctionne pas sur mac...
*/

int		free_prg(t_prg *prg)
{
	if (prg)
	{
		sem_unlink(SEM_FORKS);
		sem_unlink(SEM_WRITE);
		sem_unlink(SEM_MEAL);
		sem_unlink(SEM_STATE);
		sem_close(prg->forks);
		sem_close(prg->info.write_info);
		sem_close(prg->info.philo_state);
		sem_close(prg->info.m_meal);
		free(prg->philos);
	}
	return (0);
}
