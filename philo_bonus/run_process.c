/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:10:40 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/07 14:24:23 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_ph(t_ph *ph, t_set *setting, int size)
{
	t_ph	*tp;
	int		i;

	i = 1;
	sem_close(ph->key);
	sem_close(ph->set->died);
	sem_close(ph->set->fork);
	sem_close(ph->set->wrt);
	while (i < size)
	{
		tp = ph;
		ph = ph->next;
		free(tp);
		i++;
	}
	free(setting);
}

void	writing(char *out, t_ph *pr)
{
	size_t	now;

	now = now_time() - pr->set->start;
	keys(pr->set->wrt, 1);
	printf("%zu  %d  %s\n", now, pr->id, out);
	if (out[0] == 'd' && out[1] == 'i')
		return ;
	keys(pr->set->wrt, 0);
}

void	run_process(t_ph *ph, int size, int i)
{
	ph->set->start = now_time();
	while (ph && ++i < size)
	{
		ph->p_d = fork();
		if (ph->p_d < 0)
			ft_exit(ph);
		else if (ph->p_d == 0)
		{
			sem_unlink("/sem_keys");
			ph->key = sem_open("/sem_keys", O_CREAT, 0644, 1);
			pthread_create(&ph->th, NULL, routine, ph);
			pthread_detach(ph->th);
			while (1)
			{
				time_to_die(ph, now_time() - ph->set->start);
				nb_of_meals(ph);
			}
		}
		ph = ph->next;
	}
}
