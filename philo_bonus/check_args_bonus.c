/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:05:00 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/06 15:40:20 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	check_numeric(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == 0)
			return (WRONG_ARGUMENTS);
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (WRONG_ARGUMENTS);
			j++;
		}
		i++;
	}
	return (0);
}

static int	valid_arg(int ac, char **av)
{
	if (ft_atoi(av[1]) < 2 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0)
		return (1);
	if (ft_atoi(av[4]) < 0)
		return (1);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (1);
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (WRONG_ARGUMENTS);
	if (valid_arg(ac, av))
		return (WRONG_ARGUMENTS);
	return (check_numeric(ac, av));
}
