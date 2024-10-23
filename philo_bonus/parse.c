#include "philo_bonus.h"

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
		return (0);
	number = ft_atoi(&str[i]);
	if (number <= 0 || (ac == 1 && number > 200))
		return (-1);
	else if ((ac == 2 || ac == 3 || ac == 4) && number < 60)
		return (-1);
	return (number);
}

t_set	*parsing(int ac, char **av)
{
	int		inf[sizeof(int) * 5];
	int		i;
	t_set	*data;

	i = 0;
	while (++i < ac)
	{
		if (check_argement(av[i], i) == -1)
			return (write(2, "rules not confirmed\n", 21), NULL);
		else
			inf[i - 1] = check_argement(av[i], i);
	}
	if (ac == 5)
		inf[4] = 0;
	inf[5] = 0;
	data = create_data(inf);
	if (data == NULL)
		return (NULL);
	return (data);
}