/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:57:39 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/06 15:01:43 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

# define BOOL _Bool
# define TRUE 1
# define FALSE 0

typedef pthread_mutex_t	t_mtx;
typedef struct timeval	t_ms;
typedef struct setting
{
	int		nb_of_p;
	int		tt_d;
	int		tt_e;
	int		tt_s;
	int		nb_of_m;
	BOOL	died;
	size_t	start;
	t_mtx	*fork;
	t_mtx	m_d;
	t_mtx	wr;
}			t_set;

typedef struct philo
{
	int			id;
	int			l_f;
	int			r_f;
	int			n_meal;
	pthread_t	th;
	t_set		*set;
	t_mtx		ml_eat;
	t_mtx		m_meal;
	size_t		last_eat;
}				t_ph;

int		parsing(int ac, char **av, t_ph **ph);
t_ph	*create_data(int *data);
int		run_threads(t_ph *ph, int size);
size_t	time_to_die(t_ph *ph, size_t now);
size_t	ft_strlen(const char *s);
size_t	get_current_time(void);
int		printing(t_ph **ph, char *str);
int		u_sleep(size_t time_u_want, t_ph *ph);
int		ft_atoi(const char *str);
int		monitoring(t_ph **ph);
int		white_space(char c);
int		thinking(t_ph *tp);
int		sleeping(t_ph *tp);
int		eating(t_ph *tp);
void	destroy_mutex(t_ph **ph, int size);
void	key_mtx(t_mtx *m_x, int key);
void	init_time(t_ph *ph);
void	di_ed(BOOL *died, t_mtx mdi_ed);
#endif
