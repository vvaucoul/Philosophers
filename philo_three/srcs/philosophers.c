/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:07:01 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/01/11 14:32:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void		check_meal(void *prg_thread_param)
{
	t_prg	*prg;
	int		i;

	prg = (t_prg *)prg_thread_param;
	i = 0;
	if (philo_eat_is_zero(prg))
		return ;
	while (1 && !prg->someone_dead && !prg->no_more_meal)
	{
		sem_wait(prg->info.m_meal);
		++i;
		if (i >= (prg->n_philosophers * prg->n_philo_must_eat))
		{
			prg->no_more_meal = TRUE;
			sem_post(prg->info.global);
			sem_post(prg->info.philo_state);
			usleep(DELAY_TO_PHILOSOPHERS + 50);
			display_end_message(prg, MSG_END);
			break ;
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
			philo->prg->someone_dead = TRUE;
			sem_post(philo->prg->info.global);
			sem_post(philo->prg->info.philo_state);
			sem_post(philo->prg->info.m_meal);
			break ;
		}
	}
}

void			*routine(t_philo *philo)
{
	philo->last_meal = get_current_time();
	if (pthread_create(&philo->purgatoire, NULL, (void *)purgatoire, philo) < 0)
		return ((void *)1);
	pthread_detach(philo->purgatoire);
	if (pthread_create(&philo->prg->global_process_handler, NULL,
	(void *)cstate_child, philo->prg) < 0)
		return ((void *)1);
	pthread_detach(philo->prg->global_process_handler);
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

static int		start_process(t_prg *prg)
{
	int i;

	i = 0;
	prg->info.start_time = get_current_time();
	while (i < prg->n_philosophers)
	{
		if ((prg->philos[i].philosopher = fork()) == -1)
			return (1);
		else if (!prg->philos[i].philosopher)
		{
			routine(&prg->philos[i]);
			exit(0);
		}
		usleep(DELAY_TO_PHILOSOPHERS);
		++i;
	}
	return (0);
}

int				start_simu(t_prg *prg)
{
	if (prg->n_philo_must_eat >= 0)
	{
		if (pthread_create(&prg->check_meal, NULL,
		(void *)check_meal, (void *)prg))
			return (1);
	}
	if (start_process(prg))
		return (1);
	pthread_create(&prg->global_process_handler, NULL,
	&cstate_owner, (void *)prg);
	pthread_join(prg->check_meal, NULL);
	pthread_join(prg->global_process_handler, NULL);
	exit_process(prg);
	return (0);
}
