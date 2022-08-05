#include "philo.h"

t_philo *init_philo(t_data *data)
{
	t_philo *philo;
	int i;

	i = 0;
	philo = malloc(sizeof(t_philo)*data->num_philo);
	while(i < data->num_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = i + 1;
		philo[i].last_meal = get_time(); // 0 ???
		philo[i].data_of_philo = data;
		pthread_mutex_init(&data->fork_lock[i], NULL);
		i++;
	}
	i--;
	philo[i].right_fork = 0;
	return (philo);
}

int init_data(t_data *data, int ac, char **av)
{
	data->num_philo = ft_atoi(av[1]);//ft_atoi'ye çek
	if(data->num_philo == 1)
	{
		printf("Philo 1 died\n");
		return(1);
	}
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->must_eat = 0;
	if(ac == 6)
		data->must_eat = ft_atoi(av[5]);
	data->is_died = 0;
	data->sum_meal = 0;
	data->fork_lock = malloc(sizeof(pthread_mutex_t)* data->num_philo);
	pthread_mutex_init(&data->print_lock, NULL);
	return (0);
}

int main(int ac, char **av)
{
	if(ac > 1)
	{
		t_data data;
		t_philo *philo;

		if(init_data(&data, ac, av) == 1)
			return (0);
		check_args(&data, ac);
		philo = init_philo(&data);
		start_dinner(philo);
		fin_dinner(philo, &data);
	}
	return (0);
}