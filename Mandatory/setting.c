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
	t_ph		*tp;

	i = 0;
	tp = (*ph);
	tp[i].set->start = now;
	while (i < size)
	{
		tp[i].last_eat = 0;
		pthread_mutex_init(&tp[i].ml_eat, NULL);
		pthread_mutex_init(&tp[i].m_meal, NULL);
		i++;
	}
}

int	chopsticks(t_ph **ph, bool b)
{
	t_ph	*tp;
	size_t  now;

	tp = (*ph);
	pthread_mutex_lock(tp->writing);
	now = get_current_time() - tp->set->start;
	pthread_mutex_unlock(tp->writing);
	if (b == true)
	{
		pthread_mutex_lock(&tp->set->fork[tp->l_f]);
		if (writing(&tp, "has take a fork", now))
			return (1);
		pthread_mutex_lock(&tp->set->fork[tp->r_f]);
		if (writing(&tp, "has take a fork", now))
			return (1);
		if (writing(&tp, "is eating", now))
			return (1);
	}
	else
	{
		pthread_mutex_unlock(&tp->set->fork[tp->l_f]);
		pthread_mutex_unlock(&tp->set->fork[tp->r_f]);
	}
	return (0);
}


void	destroy_mutex(t_ph **ph, int size)
{
	int		i;
	t_ph		*tp;

	i = -1;
	tp = (*ph);
	while (++i < size)
	{
		pthread_mutex_destroy(&tp[i].ml_eat);
		pthread_mutex_destroy(&tp[i].m_meal);
	}
	i = -1;
	while (++i < size)
		pthread_mutex_destroy(&tp->set->fork[i]);
	pthread_mutex_destroy(&tp->set->md);
	pthread_mutex_destroy(&tp->set->wr);	
	free(tp->set->fork);
	free(tp->set);
	free(tp);
}