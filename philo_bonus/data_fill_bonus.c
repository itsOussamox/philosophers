/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_fill_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:12:34 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/05 20:50:08 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	time.tv_sec = time.tv_sec * 1000;
	time.tv_usec = time.tv_usec / 1000;
	return (time.tv_usec + time.tv_sec);
}

static int	philo_fill(t_data *data)
{
	int	i;
	int	id;

	sem_init(&data->forks, 1, (unsigned int)data->num_of_philos);
	sem_init(&data->print, 1, 1);
	i = 0;
	data->create_date = get_time();
	while (++i < data->num_of_philos)
	{
		data->philos[i].n = i;
		data->philos[i].data = data;
		data->philos[i].death_time = get_time() + data->time_to_die;
		id = fork();
		if (id == 0)
			monitor(&data->philos[i]);
	}
}

int	data_fill(int ac, char **av, t_data *data)
{	
	data->num_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->num_of_must_eat = ft_atoi(av[5]);
	else
		data->num_of_must_eat = -1;
	data->philos = ft_calloc(data->num_of_philos, sizeof(t_philo));
	if (!data->philos)
		return (MALLOC_ERROR);
	philo_fill(data);
	return (0);
}
