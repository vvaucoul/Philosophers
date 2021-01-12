/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:47:47 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 13:54:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# include "utils.h"

# define DEFAULT_TIME_TO_WAIT 1000
# define DELAY_TO_PHILOSOPHERS 20

# define MSG_EAT "is eating\n"
# define MSG_SLEEP "is sleeping\n"
# define MSG_FORK "has taken a fork\n"
# define MSG_THINK "is thinking\n"
# define MSG_END "must eat count has been reached\n"
# define MSG_DIED "died\n"

# define MIN_PHILOSOPHERS 2
# define MAX_PHILOSOPHERS 1000
# define MIN_TIME_TO	  0

# define UINT_MAX			4294967295
# define UINT_MIN			-4294967294

typedef	int	t_bool;
# define TRUE 1
# define FALSE 0

struct s_prg;

typedef struct			s_philo
{
	struct s_prg		*prg;
	int					position;

	int					left_fork;
	int					right_fork;

	pthread_t			philosopher;
	pthread_t			purgatoire;

	t_bool				is_eating;

	int					actu_meal;
	int64_t				last_meal;
}						t_philo;

typedef struct			s_info
{
	int64_t				start_time;
	pthread_mutex_t		write_info;
	pthread_mutex_t		philo_state;
	pthread_mutex_t		m_meal;
}						t_info;

typedef struct			s_prg
{
	int					n_philosophers;
	int64_t				time_to_die;
	int64_t				time_to_eat;
	int64_t				time_to_sleep;
	int64_t				n_philo_must_eat;

	pthread_mutex_t		*forks;
	pthread_t			check_meal;

	t_philo				*philos;
	t_info				info;

	t_bool				someone_dead;
	t_bool				no_more_meal;
}						t_prg;

/*
** Functions
*/

int						init_struct(int argc, char **argv, t_prg *prg);
int						free_prg(t_prg *prg);
int						start_simu(t_prg *prg);

/*
** Routine
*/

void					philo_routine(t_philo *philo);
int						display_message(t_prg *prg, char *msg, t_philo *philo);
int						display_end_message(t_prg *prg, char *msg);
t_bool					must_eat_has_been_reached(t_prg *prg);

#endif
