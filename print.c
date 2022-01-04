/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:02:12 by marvin            #+#    #+#             */
/*   Updated: 2022/01/03 12:02:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *philo, char *str)
{
	unsigned int	now;

	now = get_time();
	pthread_mutex_lock(&philo->data->print);
	printf("%u\t%d\t%s\n", now - philo->data->create_date, philo->n + 1, str);
	pthread_mutex_unlock(&philo->data->print);
}