/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:15:00 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/20 13:01:53 by bikourar         ###   ########.fr       */
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
		usleep(500);
	return (0);
}

size_t	time_to_die(t_ph **ph, size_t now)
{
	size_t	check_time;
	t_ph	*tp;

	tp = (*ph);
	check_time = now - tp->last_eat;
	if (check_time > (size_t)tp->set->tt_d)
		return (1);
	return (0);
}
