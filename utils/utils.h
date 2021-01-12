/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:09:48 by user42            #+#    #+#             */
/*   Updated: 2021/01/09 21:30:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# include <stdio.h>

typedef struct			s_time
{
	int64_t				start;
	int64_t				end;
}						t_time;

/*
** Lib utils
*/

int64_t					get_current_time(void);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
long					ft_atol(const char *str);
int						ft_strlen(const char *s);
int						display_error(char *error, int error_to_ret);
char					*ft_lltoa(int64_t n);
int						ft_isnum(const char *s);

/*
** Philo utils
*/

int						check_args_num(int argc, char **argv);

#endif
