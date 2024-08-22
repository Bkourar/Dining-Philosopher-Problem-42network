/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   days.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:22:55 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/22 01:03:11 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_ph **ph, size_t start)
{
	t_ph	*tp;
	size_t	now;

	tp = (*ph);
	pthread_mutex_lock(tp->writing);
	now = get_current_time() - start;
	pthread_mutex_unlock(tp->writing);
	if (chopsticks(&tp, true, now))
		return (1);
	pthread_mutex_lock(tp->dining);
	if (tp->set->died == true)
	{
		pthread_mutex_unlock(tp->dining);
		return (1);
	}
	pthread_mutex_unlock(tp->dining);
	printf("%zu  %d  is eating\n", now, tp->id);
	if (u_sleep(tp->set->tt_e))
		perror("gettimeofday");
	pthread_mutex_lock(&tp->ml_eat);
	tp->last_eat = get_current_time() - start;
	pthread_mutex_unlock(&tp->ml_eat);
	chopsticks(&tp, false, start);
	return (0);
}

int	sleeping(t_ph **ph, size_t start)
{
	t_ph	*tp;
	size_t	now;

	tp = (*ph);
	pthread_mutex_lock(tp->writing);
	now = get_current_time() - start;
	pthread_mutex_unlock(tp->writing);
	pthread_mutex_lock(tp->dining);
	if (tp->set->died == true)
	{
		pthread_mutex_unlock(tp->dining);
		return (1);
	}
	pthread_mutex_unlock(tp->dining);
	printf("%zu  %d  is sleeping\n", now, tp->id);
	if (u_sleep(tp->set->tt_s))
		perror("gettimeofday");
	return (0);
}

int	thinking(t_ph **ph, size_t start)
{
	t_ph	*tp;
	size_t	now;

	tp = (*ph);
	pthread_mutex_lock(tp->writing);
	now = get_current_time() - start;
	pthread_mutex_unlock(tp->writing);
	pthread_mutex_lock(tp->dining);
	if (tp->set->died == true)
	{
		pthread_mutex_unlock(tp->dining);
		return (1);
	}
	pthread_mutex_unlock(tp->dining);
	printf("%zu  %d  is thinking\n", now, tp->id);
	return (0);
}
