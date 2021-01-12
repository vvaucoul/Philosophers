/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:50:50 by user42            #+#    #+#             */
/*   Updated: 2021/01/11 14:13:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_routine(t_philo *philo)
{
	sem_wait(philo->prg->forks);
	display_message(philo->prg, MSG_FORK, philo);
	sem_wait(philo->prg->forks);
	display_message(philo->prg, MSG_FORK, philo);
	philo->last_meal = get_current_time();
	display_message(philo->prg, MSG_EAT, philo);
	usleep(philo->prg->time_to_eat);
	++philo->actu_meal;
	sem_post(philo->prg->info.m_meal);
	sem_post(philo->prg->forks);
	sem_post(philo->prg->forks);
}
