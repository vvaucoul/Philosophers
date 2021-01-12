/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:47:47 by user42            #+#    #+#             */
/*   Updated: 2021/01/11 14:32:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

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

# define SEM_FORKS	"S_FORKS"
# define SEM_WRITE	"S_WRITE"
# define SEM_STATE	"S_STATE"
# define SEM_MEAL	"S_MEAL"
# define SEM_GLOBAL	"S_GLOBAL"

typedef	int	t_bool;
# define TRUE 1
# define FALSE 0

struct s_prg;

typedef struct			s_philo
{
	struct s_prg		*prg;
	int					position;

	pid_t				philosopher;
	pthread_t			purgatoire;

	t_bool				is_eating;

	int					actu_meal;
	int64_t				last_meal;
}						t_philo;

typedef struct			s_info
{
	int64_t				start_time;
	sem_t				*write_info;
	sem_t				*philo_state;
	sem_t				*m_meal;
	sem_t				*global;
}						t_info;

typedef struct			s_prg
{
	int					n_philosophers;
	int64_t				time_to_die;
	int64_t				time_to_eat;
	int64_t				time_to_sleep;
	int64_t				n_philo_must_eat;

	sem_t				*forks;
	pthread_t			check_meal;
	pthread_t			global_process_handler;

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

/*
** Process param
*/

void					exit_process(t_prg *prg);
void					*cstate_owner(void *prg_thread_param);
void					*cstate_child(void *prg_thread_param);
t_bool					philo_eat_is_zero(t_prg *prg);
#endif
