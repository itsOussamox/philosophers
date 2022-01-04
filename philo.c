/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:24:11 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/03 19:37:14 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philos(t_data *data)
{
	free(data->philos);
	free(data->forks);	
}

int	main(int ac, char **av)
{
	t_data	data;
	int		error;

	memset(&data, 0, sizeof(t_data));
	pthread_mutex_init(&data.main, NULL);
	error = check_args(ac, av);
	if (error)
		return (end_program(error, &data));
	error = data_fill(ac, av, &data);	
	if (error)
		return (end_program(error, &data));

	pthread_mutex_lock(&data.main);
	pthread_mutex_lock(&data.main);
	free_philos(&data);
	puts("ALL FREED");
	return (0);
}