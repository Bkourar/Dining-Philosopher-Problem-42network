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

int	eating(t_ph **ph)
{
	t_ph	*tp;

	tp = (*ph);
	if (chopsticks(&tp, true))
		return (1);
	pthread_mutex_lock(&tp->m_meal);
	tp->n_meal++;
	pthread_mutex_unlock(&tp->m_meal);
	if (u_sleep(tp->set->tt_e))
		perror("gettimeofday");
	pthread_mutex_lock(&tp->ml_eat);
	tp->last_eat = get_current_time() - tp->set->start;
	pthread_mutex_unlock(&tp->ml_eat);
	chopsticks(&tp, false);
	return (0);
}

int	sleeping(t_ph **ph)
{
	t_ph	*tp;
	size_t  now;

	tp = (*ph);
	pthread_mutex_lock(tp->writing);
	now = get_current_time() - tp->set->start;
	pthread_mutex_unlock(tp->writing);
	if (writing(&tp, "is sleeping", now))
		return (1);
	if (u_sleep(tp->set->tt_s))
		perror("gettimeofday");
	return (0);
}

int	thinking(t_ph **ph)
{
	t_ph	*tp;
	size_t  now;

	tp = (*ph);
	pthread_mutex_lock(tp->writing);
	now = get_current_time() - tp->set->start;
	pthread_mutex_unlock(tp->writing);
	if (writing(&tp, "is thinking", now))
		return (1);
	return (0);
}
