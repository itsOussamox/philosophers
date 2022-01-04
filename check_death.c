/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:12:36 by marvin            #+#    #+#             */
/*   Updated: 2022/01/03 12:12:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *arg)
{
	t_philo			*philo;
	unsigned int	now;
	
	philo = arg;
	while (philo->data->finish == 0)
	{
		now = get_time();
		if (now - philo->last_meal > philo->data->time_to_die)
		{
			print_philo(philo, "died");
			philo->data->finish = 1;
		}
	}
	return (0);
}