/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:15:25 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/05 10:57:01 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	malloc_er(t_data *data)
{
	if (data->philos)
		free(data->philos);
	write(2, "Error: MALLOC ERROR\n", 20);
}

int	end_program(int err, t_data *data)
{
	if (err == WRONG_ARGUMENTS)
		write(2, "Error: WRONG ARGUMENTS\n", 23);
	if (err == MALLOC_ERROR)
		malloc_er(data);
	return (1);
}
