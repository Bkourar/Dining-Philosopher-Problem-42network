#include "philo_bonus.h"

t_set	*create_data(int *in)
{
	t_set	*i;

	i->nb_of_p = in[0];
	i->tt_d = in[1];
	i->tt_e = in[2];
	i->tt_s = in[3];
	i->nb_of_m = in[5];
	i->died = FALSE;
	return (free(in), i);
}

static t_ph	*update_input(int id, t_set *setin)
{
	t_ph	*new;

	new = (t_ph *)malloc(sizeof(t_ph));
	if (!new)
		return (write(2, "failed allocation\n", 19), NULL);
	new->id = id;
	new->th = sem_open();
	sem_unlink();
	new->n_meal = 0;
	new->last_eat = now_time();
	new->set = setin;
	new->next = NULL;
}

t_ph	*loding_philo(t_set *inf)
{
	t_ph	*i;
	t_ph	*k;
	t_ph	*n;
	int		j;

	i = update_input(1, inf);
	j = 0;
	k = i;
	while (j < inf->nb_of_p - 1)
	{
		add_back(i, update_input(j + 2, inf));
		if (j + 1 == inf->nb_of_p - 1)
			i->next = k;
		j++;
	}
}