/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:42:49 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/20 13:31:25 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	day(t_ph **ph, size_t init)
{
	t_ph		*tp;

	tp = (*ph);
	if (eating(&tp, init) && pthread_mutex_lock(tp->dining) == 0)
		return (1);
	sleeping(&tp, init);
	thinking(&tp, init);
	return (0);
}

void	*routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	ph->l_f = ph->id - 1;
	ph->r_f = (ph->l_f + 1) % ph->set->nb_of_p;
	ph->last_eat = 0;
	if (ph->id % 2 == 0)
		u_sleep(ph->set->tt_e);
	while (1)
	{
		if (day(&ph, ph->in_time))
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
		if (pthread_create(&tmp->th[i], NULL, routine, (void *)&tmp[i]))
			perror("THREAD create : 1");
	while (pthread_mutex_lock(tmp->dining) != 0);
	i = -1;
	while (++i < size)
		if (pthread_join(tmp->th[i], NULL) != 0)
			perror("THREAD join : 2");
}
