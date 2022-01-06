/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_fill_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:12:34 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/06 19:42:49 by obouadel         ###   ########.fr       */
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

static int	open_semaphores(t_data *data)
{
	data->forks = sem_open("forks", O_CREAT, 0644, data->num_of_philos);
	if (data->forks == SEM_FAILED)
		return (0);
	data->main = sem_open("main", O_CREAT, 0644, 0);
	if (data->main == SEM_FAILED)
		return (0);
	data->print = sem_open("print", O_CREAT, 0644, 1);
	if (data->print == SEM_FAILED)
		return (0);
	data->twoforks = sem_open("twoforks", O_CREAT, 0644, 0);
	if (data->print == SEM_FAILED)
		return (0);
	return (1);
}

static int	philo_fill(t_data *data)
{
	int			i;
	int			id;
	pthread_t	temp;

	i = -1;
	data->create_date = get_time();
	if (data->num_of_must_eat > 0)
	{
		pthread_create(&temp, NULL, check_eat, data);
		pthread_detach(temp);
	}
	while (++i < data->num_of_philos)
	{
		data->philos[i].n = i;
		data->philos[i].data = data;
		data->philos[i].death_time = get_time() + data->time_to_die;
		data->philos[i].eat = sem_open("eat", O_CREAT, 0644, 1);
		if (data->print == SEM_FAILED)
			return (SEM_ERROR);
		id = fork();
		if (id == 0)
			monitor(&data->philos[i]);
		data->philos[i].id = id;
	}
	return (0);
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
	if (!open_semaphores(data))
		return (SEM_ERROR);
	return (philo_fill(data));
}
