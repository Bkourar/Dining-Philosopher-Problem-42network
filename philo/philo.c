/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:56:34 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/06 11:27:06 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_threads(t_ph **ph, int size)
{
	t_ph	*tmp;
	int		i;

	i = -1;
	tmp = (*ph);
	while (++i < size)
	{
		if (pthread_join((*ph)[i].th, NULL) != 0)
		{
			write(2, "THREAD join is faile\n", 24);
			return (1);
		}
	}
	destroy_mutex(ph, size);
	return (0);
}

int	main(int ac, char **av)
{
	t_ph	*phi;

	phi = NULL;
	if (ac != 5 && ac != 6)
		return (write(2, "error inavalid argement\n", 25), 1);
	if (parsing(ac, av, &phi))
		return (1);
	if (run_threads(phi, phi->set->nb_of_p))
		return (1);
	if (monitoring(&phi))
		return (1);
	if (join_threads(&phi, phi->set->nb_of_p))
		return (1);
	return (0);
}
