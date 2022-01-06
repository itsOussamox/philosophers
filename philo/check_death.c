/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:12:36 by marvin            #+#    #+#             */
/*   Updated: 2022/01/05 10:26:29 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_eat(void *arg)
{
	t_philo			*philo;

	philo = arg;
	while (philo->data->finish == 0)
	{
		if (philo->data->eat_finish >= philo->data->num_of_philos)
		{
			philo->data->finish = 1;
			pthread_mutex_lock(&philo->data->print);
			pthread_mutex_lock(&philo->data->eat);
			pthread_mutex_unlock(&philo->data->main);
		}
		usleep(300);
	}
	return (0);
}

void	*check_death(void *arg)
{
	t_philo			*philo;
	unsigned int	now;

	philo = arg;
	while (philo->data->finish == 0)
	{
		now = get_time();
		if (now > philo->death_time)
		{
			print_philo(philo, "died");
			pthread_mutex_lock(&philo->eating);
			pthread_mutex_lock(&philo->data->print);
			pthread_mutex_unlock(&philo->data->main);
		}
		usleep(300);
	}
	return (0);
}
