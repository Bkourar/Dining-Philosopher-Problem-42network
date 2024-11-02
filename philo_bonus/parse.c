#include "philo_bonus.h"

void	u_sleep(size_t time_u_want)
{
	size_t	start;

	start = now_time();
	while (now_time() - start < time_u_want)
	{
		usleep(500);
	}
}

size_t	now_time(void)
{
	t_ms	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
}

static int	check_argement(const char *str, int ac)
{
	int	number;
	int	i;

	i = 0;
	while (str[i] && white_space(str[i]))
		i++;
	if (str[i] != '\0' && str[i] == '+')
		i++;
	else if (str[i] != '\0' && str[i] == '-')
		return (-1);
	number = ft_atoi(&str[i]);
	if (number <= 0 || (ac == 1 && number > 200))
		return (-1);
	else if ((ac == 2 || ac == 3 || ac == 4) && number < 60)
		return (-1);
	return (number);
}

int	parsing(int ac, char **av, t_set **data)
{
	int		inf[sizeof(int) * ac];
	int		checker;
	int		i;

	i = 0;
	while (++i < ac)
	{
		checker = check_argement(av[i], i);
		if (checker == -1)
			return (write(2, "rules not confirmed\n", 21), -1);
		else if(checker == 0)
			return (1);
		else
			inf[i - 1] = checker;
	}
	inf[ac - 1] = 0;
	(*data) = create_data(inf);
	if (data == NULL)
		return (-1);
	return (0);
}