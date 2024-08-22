/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:46:18 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/22 01:05:37 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	intial_metux(t_ph **ph, int size, size_t now)
{
	int		i;
	int		mx;
	t_ph	*tp;

	i = 0;
	tp = (*ph);
	mx = tp[i].set->nb_of_p;
	tp[i].set->start = now;
	while (i < size)
	{
		tp[i].last_eat = 0;
		pthread_mutex_init(&tp[i].ml_eat, NULL);
		i++;
	}
}

int	chopsticks(t_ph **ph, bool b, size_t now)
{
	t_ph	*tp;

	tp = (*ph);
	if (b == true)
	{
		pthread_mutex_lock(&tp->set->fork[tp->l_f]);
		pthread_mutex_lock(tp->dining);
		if (tp->set->died == true)
		{
			pthread_mutex_unlock(tp->dining);
			return (1);
		}
		pthread_mutex_unlock(tp->dining);
		// pthread_mutex_lock(tp->writing);
		printf("%zu  %d  has take a fork 1\n", now, tp->id);
		// pthread_mutex_unlock(tp->writing);
		pthread_mutex_lock(&tp->set->fork[tp->r_f]);
		pthread_mutex_lock(tp->dining);
		if (tp->set->died == true)
		{
			pthread_mutex_unlock(tp->dining);
			return (1);
		}
		pthread_mutex_unlock(tp->dining);
		// pthread_mutex_lock(tp->writing);
		printf("%zu  %d  has take a fork 2\n", now, tp->id);
		// pthread_mutex_unlock(tp->writing);
	}
	else
	{
		pthread_mutex_unlock(&tp->set->fork[tp->l_f]);
		pthread_mutex_unlock(&tp->set->fork[tp->r_f]);
	}
	return (0);
}
