/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:11:16 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/05 12:11:17 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_set	*setting;
	t_ph	*philo;
	int		i;

	philo = NULL;
	setting = NULL;
	if (ac != 5 && ac != 6)
		return (write(2, "error inavalid argement\n", 25), 1);
	if (parsing(ac, av, &setting))
		return (1);
	philo = loding_philo(setting);
	run_process(philo, setting->nb_of_p);
	i = -1;
	while (philo && ++i < setting->nb_of_p)
	{
		waitpid(philo->p_d, NULL, 0);
		philo = philo->next;
	}
	free_ph(philo, setting, setting->nb_of_p);
}
