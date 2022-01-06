/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:24:11 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/06 19:29:10 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->eat);
	pthread_mutex_destroy(&data->main);
	free(data->philos);
	free(data->forks);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		error;

	memset(&data, 0, sizeof(t_data));
	error = check_args(ac, av);
	if (error)
		return (end_program(error, &data));
	error = data_fill(ac, av, &data);
	if (error)
		return (end_program(error, &data));
	pthread_mutex_lock(&data.main);
	free_philos(&data);
	return (0);
}
