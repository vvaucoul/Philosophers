/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:16:54 by user42            #+#    #+#             */
/*   Updated: 2021/01/09 20:17:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		display_error(char *error, int error_to_ret)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	return (error_to_ret);
}
