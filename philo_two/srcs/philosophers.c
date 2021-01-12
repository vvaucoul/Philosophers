/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:07:01 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/01/10 15:24:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static t_bool	all_philosophes_meal(t_prg *prg)
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

static void		check_meal(void *prg_thread_param)
{
	t_prg	*prg;
	int		i;

	prg = (t_prg *)prg_thread_param;
	while (1 && !prg->someone_dead && !prg->no_more_meal)
	{
		i = 0;
		while ((i < prg->n_philosophers) &&
		(!prg->someone_dead && !prg->no_more_meal))
		{
			if (all_philosophes_meal(prg))
			{
				sem_wait(prg->info.philo_state);
				prg->no_more_meal = TRUE;
				display_end_message(prg, MSG_END);
				sem_post(prg->info.philo_state);
			}
			++i;
		}
	}
	return ;
}

static void		purgatoire(void *philosophe_thread_param)
{
	t_philo *philo;

	philo = (t_philo *)philosophe_thread_param;
	while (1 && !philo->prg->someone_dead && !philo->prg->no_more_meal)
	{
		if ((get_current_time() > (philo->last_meal + philo->prg->time_to_die)))
		{
			display_message(philo->prg, MSG_DIED, philo);
			sem_wait(philo->prg->info.philo_state);
			philo->prg->someone_dead = TRUE;
			sem_post(philo->prg->info.philo_state);
		}
	}
}

void			*routine(void *philosophe_thread_param)
{
	t_philo *philo;

	philo = (t_philo *)philosophe_thread_param;
	philo->last_meal = get_current_time();
	if (pthread_create(&philo->purgatoire, NULL, (void *)purgatoire, philo) < 0)
		return ((void *)1);
	pthread_detach(philo->purgatoire);
	philo->position % 2 ? 0 : usleep(philo->prg->time_to_eat);
	while (1 && !philo->prg->someone_dead && !philo->prg->no_more_meal)
	{
		philo_routine(philo);
		display_message(philo->prg, MSG_SLEEP, philo);
		usleep(philo->prg->time_to_sleep);
		display_message(philo->prg, MSG_THINK, philo);
	}
	return ((void *)0);
}

int				start_simu(t_prg *prg)
{
	int i;

	if (prg->n_philo_must_eat >= 0)
	{
		if (pthread_create(&prg->check_meal, NULL,
		(void *)check_meal, (void *)prg))
			return (1);
		pthread_detach(prg->check_meal);
	}
	i = 0;
	prg->info.start_time = get_current_time();
	while (i < prg->n_philosophers)
	{
		if (pthread_create(&prg->philos[i].philosopher, NULL,
		(void *)routine, &prg->philos[i]) < 0)
			return (1);
		usleep(DELAY_TO_PHILOSOPHERS);
		++i;
	}
	i = 0;
	while (i < prg->n_philosophers)
		pthread_join(prg->philos[i++].philosopher, NULL);
	return (0);
}
