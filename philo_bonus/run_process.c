#include "philo_bonus.h"

void add(int *ptr, int val)
{
	*ptr = *ptr + val;
}

void	free_ph(t_ph *ph, t_set *setting, int size)
{
	t_ph	*tp;
	int		i;

	i = 1;
	while(i < size)
	{
		tp = ph;
		ph = ph->next;
		free(tp);
		i++;
	}
	free(setting);
}

void	ft_exit(t_ph *ph)
{
	free_ph(ph, ph->set, ph->set->nb_of_p);
	kill(STDIN_FILENO, SIGINT);
}

void	writing(char *out, t_ph *pr)
{
	size_t	now;

	now = now_time() - pr->set->start;
	keys(pr->set->key, 1);
	if (pr->set->died == TRUE)
	{
		keys(pr->set->key, 0);
		return ;
	}
	keys(pr->set->key, 0);
	keys(pr->set->wrt, 1);
	printf("%zu  %d  %s\n", now, pr->id, out);
	keys(pr->set->wrt, 0);
}

void    run_process(t_ph *ph, int size)
{
    int i;

    i = -1;
    ph->set->start = now_time();
    while (ph && i++ < size)
    {
        ph->p_d = fork();
        if (ph->p_d < 0)
            ft_exit(ph);
        else if (ph->p_d == 0)
        {
            pthread_create(&ph->th, NULL, routine, ph);
            pthread_detach(ph->th);
            monitoring(ph, 0);
        }
		ph = ph->next;
    }
}