/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:15:00 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/22 00:58:34 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	t_ms	time;

	if (gettimeofday(&time, NULL) == -1)
		perror("gettimeofday");
	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
}

int	u_sleep(size_t time_u_want)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < time_u_want)
	{
		if (usleep(500) != 0)
			return (1);
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

void	monitoring(t_ph **ph)
{
	size_t	now;
	int		i;

	i = 0;
	while (i < (*ph)[i].set->nb_of_p)
	{
		now = get_current_time() - (*ph)[i].set->start;
		if (time_to_die(&(*ph)[i], now))
		{
			pthread_mutex_lock((*ph)[i].dining);
			(*ph)[i].set->died = true;
			pthread_mutex_unlock((*ph)[i].dining);
			printf("%zu  %d died\n", now, (*ph)[i].id);
			break ;
		}
		i = (i + 1) % (*ph)[i].set->nb_of_p;
	}
	return ;
}