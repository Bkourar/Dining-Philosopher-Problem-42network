/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:46:18 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/20 12:56:52 by bikourar         ###   ########.fr       */
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
	while (i < size)
	{
		tp[i].in_time = now;
		tp[i].last_eat = now;
		pthread_mutex_init(&tp[i].fork[i], NULL);
		i++;
	}
	pthread_mutex_init(tp->writing, NULL);
}

size_t	chopsticks(t_ph **ph, bool b, size_t start)
{
	t_ph	*tp;
	size_t	now;

	tp = (*ph);
	if (b == true)
	{
		now = get_current_time() - start;
		pthread_mutex_lock(&tp->fork[tp->l_f]);
		printf("%zu  %d  has take a fork 1\n", now, tp->id);
		pthread_mutex_lock(&tp->fork[tp->r_f]);
		printf("%zu  %d  has take a fork 2\n", now, tp->id);
	}
	return (start);
}
