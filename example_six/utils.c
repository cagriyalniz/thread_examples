#include "philo.h"

int ft_atoi(char *s)
{
	int i;
	int res;
	int sign;

	sign = 1;
	res = 0;
	i = 0;
	if(s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while(s[i] != '\0')
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10 + s[i] - 48;
			i++;
		}
		else
		{
			printf("Argument has non digit character\n");
			exit(1);
		}
	}
	
	return (sign*res);
}

void print(t_philo *philo, char *state, char c)
{
	long current_time;

	current_time = get_time() - philo->data_of_philo->start_time;
	pthread_mutex_lock(&philo->data_of_philo->print_lock);
	if(!philo->data_of_philo->is_died)
	{
		if(c == 'e')
			{
				printf("\033[1;31m");
				printf("%3ld %3d %s\n", current_time, philo->philo_id, state);
				printf("\033[0m");
			}
		else			
			printf("%3ld %3d %s\n", current_time, philo->philo_id, state);
	}
	pthread_mutex_unlock(&philo->data_of_philo->print_lock);
}

long get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void check_args(t_data *data, int ac)
{
	if(ac != 5 && ac != 6)
	{
		printf("Incorrect count of argument\n");
		exit(1);
	}
	if(data->num_philo < 1 || data->num_philo > 200 || data->t_die < 0 || //neden 200
		data->t_eat < 0 || data->t_sleep < 0 )
		{
			printf("Incorrect arguments\n");
			exit(1);
		}
}

int check_meals(t_philo *philo)
{
	int i;

	i = 0;
	if(philo->data_of_philo->must_eat > 0)
	{
		while(i < philo->data_of_philo->num_philo)
		{
			if(philo[i].ate_count == philo->data_of_philo->must_eat)
				philo->data_of_philo->sum_meal++;
			i++;
			
		}
		if(philo->data_of_philo->sum_meal >= philo->data_of_philo->num_philo)
		{
			philo->data_of_philo->is_died = 1;
			return (1);
		}
	}
	return (0);
}