/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:58:11 by bikourar          #+#    #+#             */
/*   Updated: 2024/10/17 20:41:44 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_set	*allocation(int *inf, int i)
{
	t_set	*st;

	st = (t_set *)malloc(sizeof(t_set));
	if (!st)
		return (NULL);
	st->nb_of_p = inf[0];
	st->tt_d = inf[1];
	st->tt_e = inf[2];
	st->tt_s = inf[3];
	st->nb_of_m = inf[4];
	st->died = FALSE;
	if (pthread_mutex_init(&st->m_d, NULL))
		return (write(2, "mutex init\n", 12), NULL);
	if (pthread_mutex_init(&st->wr, NULL))
		return (write(2, "mutex init\n", 12), NULL);
	st->fork = (t_mtx *)malloc(sizeof(t_mtx) * inf[0]);
	if (!st->fork)
		return (NULL);
	while (++i < inf[0])
	{
		if (pthread_mutex_init(&st->fork[i], NULL))
			return (write(2, "mutex init\n", 12), NULL);
	}
	return (st);
}

t_ph	*create_data(int *inf)
{
	t_ph	*node;
	t_set	*head;
	int		i;

	i = -1;
	head = allocation(inf, i);
	if (!head)
		return (NULL);
	node = (t_ph *)malloc(sizeof(t_ph) * inf[0]);
	if (node == NULL)
		return (write(2, "allocation fail\n", 17), NULL);
	while (++i < inf[0])
	{
		node[i].set = head;
		node[i].id = i + 1;
		node[i].l_f = i;
		node[i].r_f = (i + 1) % inf[0];
		node[i].n_meal = 0;
		node[i].last_eat = 0;
		if (pthread_mutex_init(&node[i].ml_eat, NULL))
			return (NULL);
		if (pthread_mutex_init(&node[i].m_meal, NULL))
			return (NULL);
	}
	return (node);
}
