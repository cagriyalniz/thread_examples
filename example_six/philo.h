#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data
{
	int num_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int must_eat;
	int sum_meal;
	long start_time;
	int is_died;
	pthread_mutex_t print_lock;
	pthread_mutex_t *fork_lock;
}t_data;

typedef struct s_philo
{
	pthread_t thread;
	long last_meal;
	int ate_count;
	int philo_id;
	int left_fork;
	int right_fork;
	t_data *data_of_philo;
}t_philo;

void	init_data(t_data *data, int ac, char **av);
t_philo	*init_philo(t_data *data);
//utils
void	check_args(t_data *data, int ac);
void print(t_philo *philo, char *state, char c);
long	get_time(void);
int		check_meals(t_philo *philo);
int		ft_atoi(char *str);
//dinner
void	fin_dinner(t_philo *philo, t_data *data);
void	eat_func(t_philo *philo);
void	*loop(void *val);
void	*monitoring(void *val);
void	start_dinner(t_philo *philo);

#endif