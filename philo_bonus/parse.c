/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:10:02 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/06 15:24:41 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (0);
	number = ft_atoi(&str[i]);
	if (number <= 0 || (ac == 1 && number > 200))
		return (0);
	else if ((ac == 2 || ac == 3 || ac == 4) && number < 60)
		return (0);
	return (number);
}

int	parsing(int ac, char **av, t_set **data)
{
	int	*inf;
	int	checker;
	int	i;

	i = 0;
	inf = malloc(sizeof(int) * ac);
	if (!inf)
		return (write(2, "faile allocation\n", 18), free(inf), 1);
	while (++i < ac)
	{
		checker = check_argement(av[i], i);
		if (checker == 0)
			return (write(2, "rules not confirmed\n", 21), free(inf), 1);
		else
			inf[i - 1] = checker;
	}
	inf[ac - 1] = 0;
	(*data) = create_data(inf);
	if (data == NULL)
		return (free(inf), 1);
	return (0);
}
