/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:56:19 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/18 07:43:50 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argement(const char *str, int arg_c)
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
	if (number <= 0 || (arg_c == 1 && number > 200))
		return (0);
	return (number);
}


void	parsing(int	ac, char **av, t_ph **ph)
{
	int	inf[sizeof(int) * 5];
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!check_argement(av[i], i))
			(write(2, "rules not confirmed\n", 21), exit(2));
		else
			inf[i - 1] = check_argement(av[i], i);
	}
	if (ac == 5)
		inf[4] = -1;
	inf[5] = 0;
	(*ph) = creat_data(inf, ph);
}
