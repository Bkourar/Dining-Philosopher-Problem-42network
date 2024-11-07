/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:56:19 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/06 11:47:44 by bikourar         ###   ########.fr       */
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

int	parsing(int ac, char **av, t_ph **ph)
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
	(*ph) = create_data(inf);
	if ((*ph) == NULL)
		return (free(inf), 1);
	return (0);
}
