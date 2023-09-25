/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:00:05 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/29 13:13:56 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_sem
{
	sem_t	*fork;
	sem_t	*room;
	sem_t	*dead;
}	t_sem;

typedef struct s_philo_config
{
	int			philo_id;
	t_sem		sem;
	pthread_t	thr;
	sem_t		*philo_sem;
	char		**sem_name;
	pid_t		*pid;
	int			num_of_philo;
	int			start_time;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eat_times;
	int			eat_flag;
	int			last_eat;
	int			num_of_eat;
}	t_philo_config;

int		ft_strlen(char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

int		parsing_and_check_arg(int ac, char **av, t_philo_config *info);
int		sem_print(int philo_id, char *str, t_philo_config *info);

int		get_time_ms(void);
void	ft_msleep(int time);

void	init_config(t_philo_config	*info);
void	init_philo(t_philo_config *info);
sem_t	*init_sem(char *str, unsigned int value);
char	**init_sem_name(int num_of_philo);

pid_t	create_philo(t_philo_config *info);
void	philo(t_philo_config *info);
void	philo_routine(int philo_id, t_philo_config *info);
void	philo_clear(t_philo_config *info);
void	sem_clear(t_philo_config info);

void	*monitor(void *info);
void	monitoring(t_philo_config *info, int i);
void	monitoring_eat_times(t_philo_config *info, int i);

void	wait_child_end(t_philo_config *info);
void	main_clear(t_philo_config *info);
void	philo_clear(t_philo_config *info);

#endif
