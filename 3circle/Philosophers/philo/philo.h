/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:00:05 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/26 21:09:59 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				last_eat;
	int				num_of_eat;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
}	t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	start;
	pthread_mutex_t	time;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat;
}	t_mutex;

typedef struct s_philo_config
{
	pthread_mutex_t	*fork;
	t_mutex			mutex;
	t_philo			*philo;
	pthread_t		*thr;
	int				start_time;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				eat_flag;
	int				ready_philo;
	int				check_dead;
}	t_philo_config;

int		ft_strlen(char *s);
int		ft_atoi(const char *str);

int		parsing_and_check_arg(int ac, char **av, t_philo_config *info);
int		mutex_print(int philo_id, char *str, t_philo_config *info);
int		a_philo(t_philo_config *info);

int		create_thread(t_philo_config *info);
int		join_thread(t_philo_config *info);

int		get_time_ms(void);
void	ft_msleep(int time);

int		init_fork(t_philo_config *info);
int		init_config(t_philo_config	*info);
void	init_start_time(t_philo_config *info);
void	init_philo(int *philo_id, t_philo_config *info);

void	*philo(void *philo_config_arg);
void	philo_routine(int philo_id, t_philo_config *info);

void	monitoring(t_philo_config *info, int i);
void	monitoring_eat_times(t_philo_config *info, int i);

#endif
