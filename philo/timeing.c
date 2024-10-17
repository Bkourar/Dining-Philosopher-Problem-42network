/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:15:00 by bikourar          #+#    #+#             */
/*   Updated: 2024/10/17 23:56:23 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	u_sleep(size_t time_u_want, t_ph *ph, int j)
{
	size_t	start;

	j =0;
	start = get_current_time();
	while (get_current_time() - start < time_u_want)
	{
		usleep(500);
		if (j == 0)
		{
			key_mtx(&ph->set->m_d, 1);
			if (ph->set->died == TRUE)
				return (key_mtx(&ph->set->m_d, 0), 1);
			key_mtx(&ph->set->m_d, 0);
		}
	}
	return (0);
}

size_t	time_to_die(t_ph *ph, size_t now)
{
	size_t	check_time;
	t_ph	*tp;

	tp = ph;
	pthread_mutex_lock(&tp->ml_eat);
	check_time = now - tp->last_eat;
	pthread_mutex_unlock(&tp->ml_eat);
	if (check_time >= (size_t)tp->set->tt_d)
		return (1);
	return (0);
}

static int	nb_of_meals(t_ph **ph)
{
	t_ph	*tp;
	int		i;
	int		j;

	j = 0;
	i = -1;
	tp = (*ph);
	if (tp[0].set->nb_of_m == 0)
		return (0);
	while (++i < tp[0].set->nb_of_p)
	{
		pthread_mutex_lock(&tp[i].m_meal);
		if (tp[i].n_meal >= tp[0].set->nb_of_m)
			j++;
		pthread_mutex_unlock(&tp[i].m_meal);
		if (j == tp[0].set->nb_of_p)
			return (1);
	}
	return (0);
}

static int	loop_moni(t_ph *ph, int i, BOOL b, BOOL checkmat)
{
	size_t	now;

	(void)checkmat;
	while (i < ph[0].set->nb_of_p)
	{
		now = get_current_time() - ph[0].set->start;
		if (time_to_die(&ph[i], now))
		{
			di_ed(&ph[i].set->died, ph[i].set->m_d);
			key_mtx(&ph[i].set->wr, 1);
			printf("%zu  %d died\n", now, ph[i].id);
			key_mtx(&ph[i].set->wr, 0);
			break ;
		}
		key_mtx(&ph[i].m_meal, 1);
		if (ph[i].n_meal >= ph[0].set->nb_of_m)
			b = TRUE;
		key_mtx(&ph[i].m_meal, 0);
		if (b == TRUE && nb_of_meals(&ph))
			return (di_ed(&ph[i].set->died, ph[i].set->m_d), 0);
		i = (i + 1) % ph[0].set->nb_of_p;
	}
	return (0);
}

int	monitoring(t_ph **ph)
{
	int		i;
	BOOL	b;
	BOOL	checkmat;

	i = 0;
	b = FALSE;
	checkmat = FALSE;
	loop_moni(*ph, i, b, checkmat);
	return (0);
}
