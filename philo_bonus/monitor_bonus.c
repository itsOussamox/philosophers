/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:12:38 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/05 20:38:41 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->n]);
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->n1]);
	print_philo(philo, "has taken a fork");
}

static void	eat(t_philo *philo)
{
	print_philo(philo, "is eating");
	philo->death_time = get_time() + philo->data->time_to_die;
	pthread_mutex_lock(&philo->data->eat);
	philo->num_of_eat++;
	if (philo->num_of_eat == philo->data->num_of_must_eat)
		philo->data->eat_finish++;
	pthread_mutex_unlock(&philo->data->eat);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->n]);
	pthread_mutex_unlock(&philo->data->forks[philo->n1]);
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
	pthread_t	death_thread;
	pthread_t	eat_thread;

	pthread_create(&death_thread, NULL, check_death, philo);
	pthread_detach(death_thread);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		psleep(philo);
		think(philo);
	}
}