/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:08:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/11 14:29:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*
** Free all
** Le free de free philos ne fonctionne pas sur mac...
*/

int			free_prg(t_prg *prg)
{
	if (prg)
	{
		sem_unlink(SEM_FORKS);
		sem_unlink(SEM_WRITE);
		sem_unlink(SEM_MEAL);
		sem_unlink(SEM_STATE);
		sem_unlink(SEM_GLOBAL);
		sem_close(prg->forks);
		sem_close(prg->info.write_info);
		sem_close(prg->info.philo_state);
		sem_close(prg->info.m_meal);
		sem_close(prg->info.global);
		free(prg->philos);
	}
	return (0);
}

void		exit_process(t_prg *prg)
{
	int i;

	i = 0;
	waitpid(-1, NULL, 0);
	while (i < prg->n_philosophers)
	{
		kill(prg->philos[i].philosopher, SIGTERM);
		++i;
	}
}
