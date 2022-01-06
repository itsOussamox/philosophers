/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:19:18 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/06 18:51:04 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_eat(void *arg)
{
	int		i;
	t_data	*data;

	data = arg;
	i = -1;
	while (++i < data->num_of_philos)
		sem_wait(data->twoforks);
	sem_post(data->main);
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
		if (now >= philo->death_time)
		{
			philo->data->finish = 1;
			print_philo(philo, "died");
			sem_post(philo->data->main);
		}
	}
	return (0);
}
