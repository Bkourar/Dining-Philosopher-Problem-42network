/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:42:49 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/22 00:56:03 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	writing(t_ph **ph, char *str, size_t now)
{
	t_ph	*tp;

	tp = (*ph);
	pthread_mutex_lock(tp->dining);
	if (tp->set->died == true)
	{
		pthread_mutex_unlock(tp->dining);
		return (1);
	}
	pthread_mutex_unlock(tp->dining);
	printf("%zu  %d  %s\n", now, tp->id, str);
	return (0);
}

void	*routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	if (ph->id % 2 == 0)
		u_sleep(ph->set->tt_e);
	while (1)
	{
        	if (eating(&ph))
			break ;
        	if (sleeping(&ph))
			break ;
        	if (thinking(&ph))
			break ;
	}
	return (NULL);
}

void	run_threads(t_ph **ph, int size)
{
	t_ph	*tmp;
	int		i;

	intial_metux(ph, size, get_current_time());
	i = -1;
	tmp = (*ph);
	while (++i < size)
	{
		if (pthread_create(&tmp[i].th, NULL, routine, &tmp[i]))
			perror("THREAD create : 1");
	}
	monitoring(ph);
	i = -1;
	while (++i < size)
		if (pthread_join(tmp[i].th, NULL) != 0)
			perror("THREAD join : 2");
}
