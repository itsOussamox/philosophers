/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:12:34 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/06 20:29:03 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	time.tv_sec = time.tv_sec * 1000;
	time.tv_usec = time.tv_usec / 1000;
	return (time.tv_usec + time.tv_sec);
}

static	void	philo_info(t_data *data)
{
	int	i;

	i = -1;
	data->finish = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->main, NULL);
	pthread_mutex_lock(&data->main);
	data->create_date = get_time();
	while (++i < data->num_of_philos)
	{
		data->philos[i].n = i;
		data->philos[i].n1 = (i + 1) % data->num_of_philos;
		data->philos[i].data = data;
		data->philos[i].death_time = get_time() + data->time_to_die;
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philos[i].eating, NULL);
	}
}

static void	philo_fill(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, \
		&monitor, &data->philos[i]);
		usleep(100);
	}
	i = -1;
	while (++i < data->num_of_philos)
		pthread_detach(data->philos[i].thread);
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
		data->num_of_must_eat = 0;
	data->philos = ft_calloc(data->num_of_philos, sizeof(t_philo));
	if (!data->philos)
		return (MALLOC_ERROR);
	data->forks = ft_calloc(data->num_of_philos, sizeof(pthread_mutex_t));
	if (!data->forks)
		return (MALLOC_ERROR);
	philo_info(data);
	philo_fill(data);
	return (0);
}
