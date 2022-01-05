/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:02:12 by marvin            #+#    #+#             */
/*   Updated: 2022/01/05 11:00:14 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_philo(t_philo *philo, char *str)
{
	unsigned int	now;

	sem_wait(&philo->data->print);
	now = get_time();
	printf("%u\t%d\t%s\n", now - philo->data->create_date, philo->n + 1, str);
	sem_post(&philo->data->print);
}
