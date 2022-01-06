/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:15:25 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/06 18:51:26 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	sem_er(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks != SEM_FAILED)
		sem_close(data->forks);
	if (data->main != SEM_FAILED)
		sem_close(data->main);
	if (data->print != SEM_FAILED)
		sem_close(data->print);
}

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
	if (err == SEM_ERROR)
		sem_er(data);
	return (1);
}
