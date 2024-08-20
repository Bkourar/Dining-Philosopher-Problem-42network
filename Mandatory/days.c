/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   days.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:22:55 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/20 13:30:36 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_ph **ph, size_t start)
{
	t_ph	*tp;
	size_t	now;

	tp = (*ph);
	now = get_current_time() - start;
	pthread_mutex_lock(&tp->fork[tp->l_f]);
	printf("%zu  %d  has take a fork 1\n", now, tp->id);
	pthread_mutex_lock(&tp->fork[tp->r_f]);
	printf("%zu  %d  has take a fork 2\n", now, tp->id);
	pthread_mutex_lock(tp->writing);
	printf("%zu  %d  is eating\n", now, tp->id);
	pthread_mutex_unlock(tp->writing);
	if (time_to_die(&tp, now))
	{
		pthread_mutex_lock(tp->writing);
		printf("%zu  %d  died\n", get_current_time() - tp->in_time, tp->id);
		pthread_mutex_unlock(tp->dining), exit(1);
	}
	if (u_sleep(tp->set->tt_e))
		perror("gettimeofday");
	tp->last_eat = get_current_time();
	pthread_mutex_unlock(&tp->fork[tp->l_f]);
	pthread_mutex_unlock(&tp->fork[tp->r_f]);
	return (0);
}

void	sleeping(t_ph **ph, size_t start)
{
	t_ph	*tp;
	size_t	now;

	tp = (*ph);
	now = get_current_time() - start;
	pthread_mutex_lock(tp->writing);
	printf("%zu  %d  is sleeping\n", now, tp->id);
	pthread_mutex_unlock(tp->writing);
	if (u_sleep(tp->set->tt_s))
		perror("gettimeofday");
}

void	thinking(t_ph **ph, size_t start)
{
	t_ph	*tp;
	size_t	now;

	tp = (*ph);
	now = get_current_time() - start;
	pthread_mutex_lock(tp->writing);
	printf("%zu  %d  is thinking\n", now, tp->id);
	pthread_mutex_unlock(tp->writing);
}
