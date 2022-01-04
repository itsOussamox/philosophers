/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:19:33 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/04 13:52:48 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->n]);
	pthread_mutex_lock(&philo->check_mutex);
	print_philo(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->check_mutex);
	pthread_mutex_lock(&philo->check_mutex);
	pthread_mutex_lock(&philo->data->forks[philo->n1]);
	print_philo(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->check_mutex);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_mutex);
	pthread_mutex_lock(&philo->data->dead);
	print_philo(philo, "is eating");
	philo->last_meal = get_time();
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->dead);
	pthread_mutex_unlock(&philo->check_mutex);
	pthread_mutex_unlock(&philo->data->forks[philo->n]);
	pthread_mutex_unlock(&philo->data->forks[philo->n1]);
}

static void	psleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_mutex);
	pthread_mutex_lock(&philo->data->dead);
	print_philo(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	pthread_mutex_unlock(&philo->data->dead);
	pthread_mutex_unlock(&philo->check_mutex);
}

static void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_mutex);
	print_philo(philo, "thinking");
	pthread_mutex_unlock(&philo->check_mutex);
}
void	*monitor(void *arg)
{
	t_philo		*philo;
	t_data		*data;

	philo = arg;
	data = philo->data;
	if (philo->n % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (!data->finish)
	{
		take_forks(philo);
		eat(philo);
		psleep(philo);
		think(philo);
	}
	return (0);
}