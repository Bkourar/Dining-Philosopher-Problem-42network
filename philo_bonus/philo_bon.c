/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:11:16 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/07 13:18:12 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	exit_all(t_ph *ph, pthread_t tr)
{
	keys(ph->set->died, 1);
	while (ph)
	{
		kill(ph->p_d, SIGKILL);
		if (ph->id == ph->set->nb_of_p)
			break ;
		ph = ph->next;
	}
	pthread_join(tr, NULL);
}

static void	*routine_monitor(void *arg)
{
	t_ph	*ph;

	ph = arg;
	while (waitpid(0, NULL, 0) != -1)
		;
	keys(ph->set->died, 0);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_set		*setting;
	t_ph		*philo;
	pthread_t	th;

	philo = NULL;
	setting = NULL;
	if (ac != 5 && ac != 6)
		return (write(2, "error inavalid argement\n", 25), 1);
	if (parsing(ac, av, &setting))
		return (1);
	philo = loding_philo(setting);
	run_process(philo, setting->nb_of_p, -1);
	if (pthread_create(&th, NULL, routine_monitor, philo))
		return (1);
	exit_all(philo, th);
	free_ph(philo, setting, setting->nb_of_p);
}
