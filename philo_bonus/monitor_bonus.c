/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:19:33 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/06 19:39:28 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	take_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_philo(philo, "has taken a fork");
	sem_wait(philo->data->forks);
	print_philo(philo, "has taken a fork");
}

static void	eat(t_philo *philo)
{
	sem_wait(philo->eat);
	print_philo(philo, "is eating");
	philo->death_time = get_time() + philo->data->time_to_die;
	philo->num_of_eat++;
	if (philo->data->num_of_must_eat > 0
		&& philo->num_of_eat == philo->data->num_of_must_eat)
		sem_post(philo->data->twoforks);
	sem_post(philo->eat);
	usleep(philo->data->time_to_eat * 1000);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

static void	psleep(t_philo *philo)
{
	print_philo(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

static void	think(t_philo *philo)
{
	print_philo(philo, "thinking");
}

void	monitor(t_philo *philo)
{
	pthread_t	dead_thread;

	pthread_create(&dead_thread, NULL, check_death, philo);
	pthread_detach(dead_thread);
	philo->death_time = get_time() + philo->data->time_to_die;
	while (1)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		psleep(philo);
	}
}
