/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:24:51 by obouadel          #+#    #+#             */
/*   Updated: 2022/01/03 18:43:47 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define WRONG_ARGUMENTS 1
# define MALLOC_ERROR 2
# define PTHREAD_CREATE_ERROR 3
# define PTHREAD_JOIN_ERROR 4

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*                Data && Structures               */

typedef struct s_philo
{
	int				n;
	int				n1;
	int				num_of_eat;
	int				philo_must_eat;
	unsigned int	last_meal;
	pthread_mutex_t	check_mutex;
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
	unsigned int	create_date;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	main;
	t_philo			*philos;
}				t_data;

/*                MAIN FUNCTIONS                */
int		data_fill(int ac, char **av, t_data *data);
int		data_join(t_data *data);
void	*monitor(void *arg);
void	*check_death(void *arg);

/*                ERROR FUNCTIONS                */
int		check_args(int ac, char **av);
int		end_program(int err, t_data *data);

/*                UTILS FUNCTIONS                */
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
unsigned int	get_time(void);
void			print_philo(t_philo *philo, char *str);

#endif
