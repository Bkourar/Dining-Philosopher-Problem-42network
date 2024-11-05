/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:06:50 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/05 12:13:44 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_set	*create_data(int *in)
{
	t_set	*s;

	s = malloc(sizeof(t_set));
	if (s == NULL)
		return (write(2, "failed allocation\n", 19), NULL);
	s->nb_of_p = in[0];
	s->tt_d = in[1];
	s->tt_e = in[2];
	s->tt_s = in[3];
	if (in[4] > 0)
		s->nb_of_m = in[4];
	else
		s->nb_of_m = 0;
	sem_unlink("/sem_fork");
	sem_unlink("/sem_eating");
	sem_unlink("/sem_printing");
	s->fork = sem_open("/sem_fork", O_CREAT, 0644, in[0]);
	s->wrt = sem_open("/sem_printing", O_CREAT, 0644, 1);
	return (free(in), s);
}

static t_ph	*update_input(int id, t_set *setin, t_ph *hd)
{
	t_ph	*new;

	new = (t_ph *)malloc(sizeof(t_ph));
	if (!new)
	{
		free_ph(hd, setin, id);
		return (write(2, "failed allocation\n", 19), NULL);
	}
	new->id = id;
	new->nmeal = setin->nb_of_m;
	new->leat = 0;
	new->set = setin;
	new->next = NULL;
	return (new);
}

t_ph	*loding_philo(t_set *inf)
{
	t_ph	*c_ph;
	t_ph	*n_ph;
	t_ph	*o_ph;
	int		i;

	n_ph = NULL;
	c_ph = NULL;
	c_ph = update_input(1, inf, c_ph);
	if (c_ph == NULL)
		exit(1);
	i = 1;
	o_ph = c_ph;
	while (i < inf->nb_of_p)
	{
		n_ph = update_input(i + 1, inf, c_ph);
		if (n_ph == NULL)
			exit(1);
		o_ph->next = n_ph;
		o_ph = o_ph->next;
		i++;
	}
	if (n_ph)
		n_ph->next = c_ph;
	return (c_ph);
}
