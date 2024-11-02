#include "philo_bonus.h"

static size_t	time_to_die(t_ph *pr, size_t now)
{
	size_t	check_time;

	keys(pr->set->key, 1);
	check_time = now - pr->leat;
	keys(pr->set->key, 0);
	if (check_time >= (size_t)pr->set->tt_d)
		return (1);
	return (0);
}

static int	nb_of_meals(t_ph *pr)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (pr[0].set->nb_of_m == 0)
		return (0);
	while (++i < pr->set->nb_of_p)
	{
		keys(pr->set->key, 1);
		if (pr[i].nmeal >= pr[0].set->nb_of_m)
			j++;
		keys(pr->set->key, 0);
		if (j == pr->set->nb_of_p)
			return (1);
		pr = pr->next;
	}
	return (0);
}

void	monitoring(t_ph *pr, size_t	now)
{
	BOOL	b;

	b = FALSE;
	while (1)
	{
		now = now_time() - pr->set->start;
		if (time_to_die(pr, now))
		{
			keys(pr->set->key, 1);
			pr->set->died = TRUE;
			(keys(pr->set->key, 0), keys(pr->set->wrt, 1));
			printf("%zu  %d died\n", now, pr->id);
			(keys(pr->set->wrt, 0), kill(STDIN_FILENO, SIGINT));
		}
		keys(pr->set->key, 1);
		if (pr->nmeal >= pr->set->nb_of_m)
			b = TRUE;
		keys(pr->set->key, 0);
		if (b == TRUE && nb_of_meals(pr))
		{
			keys(pr->set->key, 1);
			pr->set->died = TRUE;
			(keys(pr->set->key, 0), exit(0));
		}
	}
}