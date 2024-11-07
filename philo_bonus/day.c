/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:08:05 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/06 22:17:31 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	keys(sem_t *sem, int lock)
{
	if (lock == 1)
		sem_wait(sem);
	else if (lock == 0)
		sem_post(sem);
}

static void	eating(t_ph *ph)
{
	keys(ph->set->fork, 1);
	writing("has taken a fork", ph);
	keys(ph->set->fork, 1);
	writing("has taken a fork", ph);
	writing("is eating", ph);
	keys(ph->key, 1);
	ph->leat = now_time() - ph->set->start;
	keys(ph->key, 0);
	u_sleep(ph->set->tt_e);
	keys(ph->set->fork, 0);
	keys(ph->set->fork, 0);
}

static void	sleeping(t_ph *ph)
{
	writing("is sleeping", ph);
	u_sleep(ph->set->tt_s);
}

static void	thinking(t_ph *ph)
{
	writing("is thinking", ph);
}

void	*routine(void *arg)
{
	t_ph	*ph;

	ph = arg;
	if (ph->id % 2 == 0)
		u_sleep(ph->set->tt_e);
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
		keys(ph->key, 1);
		if (ph->set->nb_of_m > 0 && ph->nmeal != 0)
			ph->nmeal--;
		if (ph->set->nb_of_m > 0 && ph->nmeal == 0)
		{
			keys(ph->key, 0);
			break ;
		}
		keys(ph->key, 0);
	}
	return (NULL);
}
