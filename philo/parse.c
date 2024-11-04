/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:56:19 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/04 21:56:33 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

t_ph	*parsing(int ac, char **av)
{
	int		inf[sizeof(int) * 5];
	int		i;
	t_ph	*ph;

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
	ph = create_data(inf);
	if (ph == NULL)
		return (NULL);
	return (ph);
}
