/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:47:27 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 12:37:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Main function
*/

#include "philo_one.h"

int		main(int argc, char **argv)
{
	t_prg	prg;

	if ((init_struct(argc, argv, &prg)))
		return (1);
	if (start_simu(&prg))
	{
		free_prg(&prg);
		return (display_error("fatal error", 1));
	}
	free_prg(&prg);
	return (0);
}
