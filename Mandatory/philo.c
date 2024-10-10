/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:56:34 by bikourar          #+#    #+#             */
/*   Updated: 2024/10/10 13:25:31 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void f()
// {
//         system("leaks philo");
// }

int	main(int ac, char **av)
{
	t_ph	*phi;
	int		i;

	// atexit(f);
	phi = NULL;
	if (ac != 5 && ac != 6)
		return (write(2, "error inavalid argement\n", 25), 1);
	parsing(ac, av, &phi);
	i = phi->set->nb_of_p;
	run_threads(&phi, i);
	// monitoring(&phi);
	return (0);
}