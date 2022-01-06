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

	now = get_time();
	sem_wait(philo->data->print);
	printf("%u\t%d\t%s\n", now - philo->data->create_date, philo->n + 1, str);
	if (philo->data->finish == 1)
		return ;
	sem_post(philo->data->print);
}
