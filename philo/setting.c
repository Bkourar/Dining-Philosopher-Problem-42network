/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:46:18 by bikourar          #+#    #+#             */
/*   Updated: 2024/10/17 22:58:22 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	t_ms	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
}

void	init_time(t_ph *ph)
{
	size_t	now;
	int		i;

	i = -1;
	now = get_current_time();
	while (++i < ph[0].set->nb_of_p)
		ph[i].set->start = now;
}

void	destroy_mutex(t_ph **ph, int size)
{
	t_ph	*tp;
	int		i;

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
	pthread_mutex_destroy(&tp->set->m_d);
	free(tp->set->fork);
	free(tp->set);
	free(tp);
}

void	di_ed(BOOL *died, t_mtx mdi_ed)
{
	key_mtx(&mdi_ed, 1);
	*died = TRUE;
	key_mtx(&mdi_ed, 0);
}
