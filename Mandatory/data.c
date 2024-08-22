/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:58:11 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/22 00:56:34 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_ph	*allocation(int *inf, t_set **st)
{
	int		i;
	t_ph	*node;

	node = (t_ph *)malloc(sizeof(t_ph) * inf[0]);
	if (!node)
		return (NULL);
	*st = (t_set *)malloc(sizeof(t_set));
	if (!(*st))
			return (NULL);
	(*st)->nb_of_p = inf[0];
	(*st)->tt_d = inf[1];
	(*st)->tt_e = inf[2];
	(*st)->tt_s = inf[3];
	(*st)->nb_of_m = inf[4];
	(*st)->died = false;
	(*st)->fork = (t_mtx *)malloc(sizeof(t_mtx) * inf[0]);
	if (!(*st)->fork)
		return (NULL);
	pthread_mutex_init(&(*st)->wr, NULL);
	pthread_mutex_init(&(*st)->md, NULL);
	i = -1;
	while (++i < inf[0])
		pthread_mutex_init(&(*st)->fork[i], NULL);
	return (node);
}

t_ph	*creat_data(int *inf, t_ph **ph)
{
	t_ph	*node;
	t_set	*head;
	int		i;

	node = allocation(inf, &head);
	if (!node)
		(write(2, "allocation fail\n", 17), exit(2));
	i = -1;
	while (++i < inf[0])
	{
		node[i].id = i + 1;
		node[i].l_f = i;
		node[i].r_f = (i + 1) % inf[0];
		node[i].n_meal = 0;
		node[i].set = head;
		node[i].writing = &node[i].set->wr;
		node[i].dining = &node[i].set->md;
		pthread_mutex_init(&node[i].ml_eat, NULL);
	}
	return ((*ph) = node, (*ph));
}
