/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:19:27 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 15:13:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			display_end_message(t_prg *prg, char *msg)
{
	char	*tmp;
	int64_t	current_time;

	sem_wait(prg->info.write_info);
	current_time = (get_current_time() - prg->info.start_time);
	ft_putstr_fd(tmp = ft_lltoa(current_time), 1);
	free(tmp);
	ft_putstr_fd("\t ", 1);
	ft_putstr_fd(msg, 1);
	sem_post(prg->info.write_info);
	return (0);
}

int			display_message(t_prg *prg, char *msg, t_philo *philo)
{
	int64_t current_time;
	char	*tmp;

	sem_wait(prg->info.write_info);
	if (!philo->prg->someone_dead && !prg->no_more_meal)
	{
		current_time = (get_current_time() - prg->info.start_time);
		ft_putstr_fd(tmp = ft_lltoa(current_time), 1);
		free(tmp);
		ft_putstr_fd("\t ", 1);
		ft_putstr_fd(tmp = ft_lltoa(philo->position + 1), 1);
		free(tmp);
		ft_putstr_fd(" ", 1);
	}
	else
	{
		sem_post(prg->info.write_info);
		return (1);
	}
	ft_putstr_fd(msg, 1);
	sem_post(prg->info.write_info);
	return (0);
}
