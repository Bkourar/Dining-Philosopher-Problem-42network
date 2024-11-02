#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_set	*setting;
	t_ph	*philo;
	int		i;

	philo = NULL;
	setting = NULL;
	if (ac != 5 && ac != 6)
		return (write(2, "error inavalid argement\n", 25), 1);
	i = parsing(ac, av, &setting);
	if (i == -1)
		return (1);
	else if (i == 1)
		return (0);
	philo = loding_philo(setting);
	run_process(philo, setting->nb_of_p);
	i = -1;
	while (philo && ++i < setting->nb_of_p)
	{
		waitpid(philo->p_d, NULL, 0);
		philo  = philo->next;
	}
	free_ph(philo, setting, setting->nb_of_p);
}
