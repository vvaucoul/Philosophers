/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:37:58 by user42            #+#    #+#             */
/*   Updated: 2021/01/11 14:00:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*cstate_owner(void *prg_thread_param)
{
	t_prg *prg;

	prg = (t_prg *)prg_thread_param;
	sem_wait(prg->info.global);
	prg->someone_dead = TRUE;
	return ((void *)0);
}

void	*cstate_child(void *prg_thread_param)
{
	t_prg *prg;

	prg = (t_prg *)prg_thread_param;
	sem_wait(prg->info.philo_state);
	prg->someone_dead = TRUE;
	sem_post(prg->info.philo_state);
	return ((void *)0);
}
