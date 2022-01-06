/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:24:51 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/06 19:32:29 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define WRONG_ARGUMENTS 1
# define MALLOC_ERROR 2
# define SEM_ERROR 3

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

/*                Data && Structures               */

typedef struct s_philo
{
	int				n;
	int				id;
	int				n1;
	int				num_of_eat;
	unsigned int	death_time;
	sem_t			*eat;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_of_philos;
	unsigned int	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				finish;
	int				eat_finish;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*main;
	sem_t			*twoforks;
	unsigned int	create_date;
	t_philo			*philos;
}					t_data;

/*                MAIN FUNCTIONS                */
int				data_fill(int ac, char **av, t_data *data);
void			monitor(t_philo *philo);
void			*check_death(void *arg);
void			*check_eat(void *arg);
void			print_philo(t_philo *philo, char *str);
/*                ERROR FUNCTIONS                */
int				check_args(int ac, char **av);
int				end_program(int err, t_data *data);

/*                UTILS FUNCTIONS                */
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
unsigned int	get_time(void);

#endif
