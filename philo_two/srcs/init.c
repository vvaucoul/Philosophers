/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:54:19 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 15:23:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** Check argc & argv validity
*/

static int		check_error_init(int argc, char **argv)
{
	if ((argc == 5) || (argc == 6))
	{
		if (ft_atol(argv[1]) < MIN_PHILOSOPHERS ||
		ft_atol(argv[1]) > MAX_PHILOSOPHERS ||
		ft_atol(argv[2]) < MIN_TIME_TO ||
		ft_atol(argv[2]) >= UINT_MAX ||
		ft_atol(argv[2]) <= UINT_MIN ||
		ft_atol(argv[3]) < MIN_TIME_TO ||
		ft_atol(argv[3]) >= UINT_MAX ||
		ft_atol(argv[3]) <= UINT_MIN ||
		ft_atol(argv[4]) < MIN_TIME_TO ||
		ft_atol(argv[4]) >= UINT_MAX ||
		ft_atol(argv[4]) <= UINT_MIN ||
		check_args_num(argc, argv))
			return (display_error("bad arguments", 1));
		if (((argc == 6) && ((ft_atol(argv[5]) < 0 ||
		ft_atol(argv[5]) <= UINT_MIN)
		|| ft_atol(argv[5]) >= UINT_MAX)))
			return (display_error("bad arguments", 1));
	}
	else
		return (display_error("bad arguments", 1));
	return (0);
}

/*
** INit philosophers
*/

static int		init_philosophers(t_prg *prg)
{
	int i;

	i = 0;
	if (!(prg->philos = malloc(sizeof(t_philo) * (prg->n_philosophers))))
		return (display_error("malloc error", 1));
	while (i < prg->n_philosophers)
	{
		prg->philos[i].position = i;
		prg->philos[i].actu_meal = 0;
		prg->philos[i].last_meal = get_current_time();
		prg->philos[i].is_eating = FALSE;
		prg->philos[i].prg = &(*prg);
		++i;
	}
	return (0);
}

/*
** Init argc & argv values
*/

static t_prg	*init_prg_values(t_prg *prg, int argc, char **argv)
{
	prg->n_philosophers = ft_atol(argv[1]);
	prg->time_to_die = ft_atol(argv[2]);
	prg->time_to_eat = ft_atol(argv[3]) * DEFAULT_TIME_TO_WAIT;
	prg->time_to_sleep = ft_atol(argv[4]) * DEFAULT_TIME_TO_WAIT;
	if (argc == 6)
		prg->n_philo_must_eat = ft_atol(argv[5]);
	else
		prg->n_philo_must_eat = -1;
	prg->no_more_meal = FALSE;
	prg->someone_dead = FALSE;
	if ((init_philosophers(prg)))
		return (NULL);
	return (prg);
}

/*
** Init other mutexes
** [fork | write]
*/

static int		init_semaphores(t_prg *prg)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_STATE);
	sem_unlink(SEM_MEAL);
	if ((prg->forks = sem_open(SEM_FORKS, O_CREAT, 0644, prg->n_philosophers))
	== SEM_FAILED)
		return (1);
	if ((prg->info.write_info = sem_open(SEM_WRITE, O_CREAT, 0644, 1))
	== SEM_FAILED)
		return (1);
	if ((prg->info.philo_state = sem_open(SEM_STATE, O_CREAT, 0644, 1))
	== SEM_FAILED)
		return (1);
	if ((prg->info.m_meal = sem_open(SEM_MEAL, O_CREAT, 0644, 1))
	== SEM_FAILED)
		return (1);
	return (0);
}

int				init_struct(int argc, char **argv, t_prg *prg)
{
	if (check_error_init(argc, argv))
		return (1);
	if (!(init_prg_values(prg, argc, argv)))
		return (1);
	if ((init_semaphores(prg)))
		return (1);
	return (0);
}
