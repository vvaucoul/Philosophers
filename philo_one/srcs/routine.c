/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:50:50 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 13:49:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->prg->forks[philo->right_fork]);
	display_message(philo->prg, MSG_FORK, philo);
	pthread_mutex_lock(&philo->prg->forks[philo->left_fork]);
	display_message(philo->prg, MSG_FORK, philo);
	philo->last_meal = get_current_time();
	display_message(philo->prg, MSG_EAT, philo);
	usleep(philo->prg->time_to_eat);
	pthread_mutex_lock(&philo->prg->info.m_meal);
	++philo->actu_meal;
	pthread_mutex_unlock(&philo->prg->info.m_meal);
	pthread_mutex_unlock(&philo->prg->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->prg->forks[philo->left_fork]);
}
