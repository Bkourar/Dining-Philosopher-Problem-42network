/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:46:18 by bikourar          #+#    #+#             */
/*   Updated: 2024/10/10 14:54:13 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	check_d(t_ph **p)
// {
// 	pthread_mutex_lock((*p)->dining);
// 	if ((*p)->set->died == true)
// 	{
// 		pthread_mutex_unlock((*p)->dining);
// 		return (1);
// 	}
// 	pthread_mutex_unlock((*p)->dining);
// 	return (0);
// }


static void	lock_unlock(t_ph *tp, bool b, int for_k)
{
	int	x;

	x = for_k % 2;
	if (b == true && x == 0)
		pthread_mutex_lock(&tp->set->fork[tp->l_f]);
	else if (b == true && x != 0)
		pthread_mutex_lock(&tp->set->fork[tp->r_f]);
	else if (b == false && x == 0)
		pthread_mutex_unlock(&tp->set->fork[tp->l_f]);
	else if (b == false && x != 0)
		pthread_mutex_unlock(&tp->set->fork[tp->r_f]);
}


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
	size_t  n;

	tp = (*ph);
	pthread_mutex_lock(tp->writing);
	n = get_current_time() - tp->set->start;
	pthread_mutex_unlock(tp->writing);
	if (b == true)
	{
		lock_unlock(tp, true, tp->l_f);
		if (writing(&tp, "has take a fork", n))
			return (1);
		if (tp->set->nb_of_p == 1)
			return (lock_unlock(tp, false, tp->l_f), 1);
		lock_unlock(tp, true, tp->r_f);
		if (writing(&tp, "has take a fork", n) || writing(&tp, "is eating", n))
			return (1);
	}
	else
	(lock_unlock(tp, false, tp->l_f), lock_unlock(tp, false, tp->r_f));
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