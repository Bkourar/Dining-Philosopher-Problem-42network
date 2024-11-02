#include "philo_bonus.h"

void    keys(sem_t *sem, int lock)
{
    if (lock == 1)
        sem_wait(sem);
    else if (lock == 0)
        sem_post(sem);
}

static void eating(t_ph *ph)
{
    keys(ph->set->fork, 1);
    writing("has taken a fork", ph);
    if (ph->set->nb_of_p == 1)
        (keys(ph->set->fork, 0), exit(1));
    keys(ph->set->fork, 1);
    writing("has taken a fork", ph);
    writing("is eating", ph);
    if (ph->set->nb_of_m > 0)
	    (keys(ph->set->key, 1), add(&ph->nmeal, 1), keys(ph->set->key, 0));
    keys(ph->set->key, 1);
    ph->leat = now_time() - ph->set->start;
    keys(ph->set->key, 0);
    u_sleep(ph->set->tt_e);
    keys(ph->set->fork, 0);
    keys(ph->set->fork, 0);
}

static void sleeping(t_ph *ph)
{
    writing("is sleeping", ph);
    u_sleep(ph->set->tt_s);
}

static void thinking(t_ph *ph)
{
    writing("is thinking", ph);
}

void	*routine(void *arg)
{
	t_ph	*ph;

	ph = arg;
	if (ph->id % 2 == 0)
		u_sleep(ph->set->tt_e);
	while (1)
	{
		eating(ph);
        sleeping(ph);
        thinking(ph);
	}
	return (NULL);
}