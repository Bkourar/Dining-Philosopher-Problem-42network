#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
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
	BOOL	died;
	size_t	start;
}			t_set;

typedef struct philo
{
	sem_t			th;
	t_set			*set;
	size_t			last_eat;
	int				id;
	int				n_meal;
	struct philo	*next;
}				t_ph;

t_set	*create_data(int *in);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		white_space(char c);
t_set	*parsing(int ac, char **av);
t_ph	*loding_philo(t_set *inf);
size_t	now_time(void);
void	add_back(t_ph **lst, t_ph *new);
#endif