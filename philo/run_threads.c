/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:42:49 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/05 13:58:07 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	printing(t_ph **ph, char *str)
{
	t_ph	*tp;
	size_t	now;

	tp = (*ph);
	now = get_current_time() - tp->set->start;
	key_mtx(&tp->set->m_d, 1);
	if (tp->set->died == TRUE)
		return (key_mtx(&tp->set->m_d, 0), 1);
	key_mtx(&tp->set->m_d, 0);
	key_mtx(&tp->set->wr, 1);
	printf("%zu  %d  %s\n", now, tp->id, str);
	key_mtx(&tp->set->wr, 0);
	return (0);
}

void	*routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	if (ph->id % 2 == 0)
		u_sleep(ph->set->tt_e, ph);
	while (1)
	{
		if (eating(ph))
			break ;
		if (sleeping(ph))
			break ;
		if (thinking(ph))
			break ;
	}
	return (NULL);
}

int	run_threads(t_ph *ph, int size)
{
	int		i;

	i = -1;
	init_time(ph);
	while (++i < size)
	{
		if (pthread_create(&(ph[i]).th, NULL, routine, &ph[i]))
		{
			write(2, "THREAD create is faile\n", 24);
			return (1);
		}
	}
	return (0);
}
