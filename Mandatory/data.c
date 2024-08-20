/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:58:11 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/20 09:24:38 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_ph	*allocation(int size)
{
	t_ph	*node;
	int		i;

	node = (t_ph *)malloc(sizeof(t_ph) * size);
	if (!node)
		return (NULL);
	node->th = (pthread_t *)malloc(sizeof(pthread_t) * size);
	if (!node->th)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		node[i].set = malloc(sizeof(t_set));
		if (!node[i].set)
			return (NULL);
		node[i].fork = (t_mtx *)malloc(sizeof(t_mtx) * size);
		if (!node[i].fork)
			return (NULL);
	}
	return (node);
}

t_ph	*creat_data(int *inf, t_ph **ph)
{
	t_ph	*node;
	t_mtx	*wr;
	t_mtx	*die;
	int		i;

	node = allocation(inf[0]);
	wr = (t_mtx *)malloc(sizeof(t_mtx));
	die = (t_mtx *)malloc(sizeof(t_mtx));
	if (!wr || !node || !die)
		(write(2, "allocation fail\n", 17), exit(2));
	i = -1;
	while (++i < inf[0])
	{
		node[i].set->nb_of_p = inf[0];
		node[i].set->tt_d = inf[1];
		node[i].set->tt_e = inf[2];
		node[i].set->tt_s = inf[3];
		node[i].set->nb_of_m = inf[4];
		node[i].writing = wr;
		node[i].dining = die;
	}
	i = -1;
	while (++i < inf[0])
		node[i].id = i + 1;
	return ((*ph) = node, (*ph));
}
