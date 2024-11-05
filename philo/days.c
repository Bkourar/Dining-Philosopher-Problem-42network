/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   days.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:22:55 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/05 13:58:20 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	key_mtx(t_mtx *m_x, int key)
{
	if (key == 1)
		pthread_mutex_lock(m_x);
	else if (key == 0)
		pthread_mutex_unlock(m_x);
}

static void	plu(int *ptr, int val)
{
	*ptr = *ptr + val;
}

int	eating(t_ph *tp)
{
	key_mtx(&tp->set->fork[tp->l_f], 1);
	if (printing(&tp, "has taken a fork") || tp->set->nb_of_p == 1)
		return (key_mtx(&tp->set->fork[tp->l_f], 0), 1);
	key_mtx(&tp->set->fork[tp->r_f], 1);
	if (printing(&tp, "has taken a fork"))
		return (key_mtx(&tp->set->fork[tp->l_f], 0)
			, key_mtx(&tp->set->fork[tp->r_f], 0), 1);
	if (printing(&tp, "is eating"))
		return (key_mtx(&tp->set->fork[tp->l_f], 0)
			, key_mtx(&tp->set->fork[tp->r_f], 0), 1);
	if (tp->set->nb_of_m > 0)
		(key_mtx(&tp->m_meal, 1), plu(&tp->n_meal, 1), key_mtx(&tp->m_meal, 0));
	key_mtx(&tp->ml_eat, 1);
	tp->last_eat = get_current_time() - tp->set->start;
	key_mtx(&tp->ml_eat, 0);
	if (u_sleep(tp->set->tt_e, tp))
		return (key_mtx(&tp->set->fork[tp->l_f], 0)
			, key_mtx(&tp->set->fork[tp->r_f], 0), 1);
	(key_mtx(&tp->set->fork[tp->l_f], 0), key_mtx(&tp->set->fork[tp->r_f], 0));
	return (0);
}

int	sleeping(t_ph *tp)
{
	if (printing(&tp, "is sleeping"))
		return (1);
	if (u_sleep(tp->set->tt_s, tp))
		return (1);
	return (0);
}

int	thinking(t_ph *tp)
{
	if (printing(&tp, "is thinking"))
		return (1);
	return (0);
}
