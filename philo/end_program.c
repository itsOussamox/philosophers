/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:15:25 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/04 16:15:31 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	malloc_er(t_data *data)
{
	if (data->philos)
		free(data->philos);	
	write(2, "Error: MALLOC ERROR\n", 20);
}

static void	pthread_er(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	write(2, "Error: PTHREAD CREATE ERROR\n", 28);
}

static void	pthread_jer(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	write(2, "Error: PTHREAD JOIN ERROR\n", 26);
}

int	end_program(int err, t_data *data)
{
	if (err == WRONG_ARGUMENTS)
		write(2, "Error: WRONG ARGUMENTS\n", 23);
	if (err == MALLOC_ERROR)
		malloc_er(data);	
	if (err == PTHREAD_CREATE_ERROR)
		pthread_er(data);
	if (err == PTHREAD_JOIN_ERROR)
		pthread_jer(data);
	return (1);
}