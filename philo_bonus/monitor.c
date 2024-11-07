/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:08:23 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/07 13:17:55 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	time_to_die(t_ph *pr, size_t now)
{
	size_t	check_time;

	keys(pr->key, 1);
	check_time = now - pr->leat;
	keys(pr->key, 0);
	if (check_time >= (size_t)pr->set->tt_d)
	{
		writing("died", pr);
		keys(pr->set->died, 0);
	}
}

void	nb_of_meals(t_ph *pr)
{
	if (pr->set->nb_of_m == 0)
		return ;
	keys(pr->key, 1);
	if (pr->nmeal == 0)
		(keys(pr->key, 0), exit(0));
	keys(pr->key, 0);
}

void	add(int *ptr, int val)
{
	*ptr = *ptr + val;
}

void	ft_exit(t_ph *ph)
{
	free_ph(ph, ph->set, ph->set->nb_of_p);
	kill(STDIN_FILENO, SIGINT);
}
