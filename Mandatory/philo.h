/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:57:39 by bikourar          #+#    #+#             */
/*   Updated: 2024/08/20 13:10:07 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>

# define bool _Bool
# define true 1
# define false 0

typedef pthread_mutex_t t_mtx;
typedef struct timeval t_ms;

typedef struct setting
{
	int		nb_of_p;
	int		tt_d;
	int		tt_e;
	int		tt_s;
	int		nb_of_m;
}			t_set;

typedef struct philo
{
	int				id;
	int				l_f;
	int				r_f;
	t_set			*set;
	pthread_t		*th;
	t_mtx			*fork;
	t_mtx			*writing;
	t_mtx			*dining;
	size_t			in_time;
	size_t			last_eat;
}					t_ph;


void	parsing(int	ac, char **av, t_ph **phi);
void	run_threads(t_ph **ph, int size);
t_ph	*creat_data(int *data, t_ph **ph);
t_ph	*allocation(int size);
int		ft_atoi(const char *str);
int		white_space(char c);
int		ft_isdigit(char c);
size_t	ft_strlen(const char *s);

//--------------------------------------------
// void	intial_metux(t_ph **ph, int size);
size_t	chopsticks(t_ph **ph, bool b, size_t start);
void	intial_metux(t_ph **ph, int size, size_t now);
// void	init_forkes(t_ph **ph, int size);

//--------------------------------------------
int		u_sleep(size_t time_u_want);
size_t	get_current_time(void);
size_t	time_to_die(t_ph **ph, size_t now);

//--------------------------------------------
void	sleeping(t_ph **ph, size_t start);
void	thinking(t_ph **ph, size_t start);
int		eating(t_ph **ph, size_t start);

#endif