/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:10:24 by bikourar          #+#    #+#             */
/*   Updated: 2024/11/07 14:26:20 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdlib.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BOOL _Bool
# define TRUE 1
# define FALSE 0

typedef struct timeval	t_ms;

typedef struct setting
{
	int		nb_of_p;
	int		tt_d;
	int		tt_e;
	int		tt_s;
	int		nb_of_m;
	size_t	start;
	sem_t	*fork;
	sem_t	*died;
	sem_t	*wrt;
}			t_set;

typedef struct philo
{
	pthread_t		th;
	pid_t			p_d;
	t_set			*set;
	sem_t			*key;
	size_t			leat;
	int				id;
	int				nmeal;
	struct philo	*next;
}					t_ph;

t_set	*create_data(int *in);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		white_space(char c);
int		parsing(int ac, char **av, t_set **data);
t_ph	*loding_philo(t_set *inf);
size_t	now_time(void);
void	free_ph(t_ph *ph, t_set *setting, int size);
void	run_process(t_ph *ph, int size, int i);
void	ft_exit(t_ph *ph);
void	*routine(void *arg);
void	u_sleep(size_t time_u_want);
void	add(int *ptr, int val);
void	keys(sem_t *sem, int lock);
void	writing(char *out, t_ph *pr);
void	nb_of_meals(t_ph *pr);
void	time_to_die(t_ph *pr, size_t now);
#endif