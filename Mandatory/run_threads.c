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

static int	day(t_ph **ph, size_t init)
{
	t_ph		*tp;

	tp = (*ph);
	if (eating(&tp, init))
		return (1);
	if (sleeping(&tp, init))
		return (1);
	if (thinking(&tp, init))
		return (1);
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
		if (day(&ph, ph->set->start))
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
