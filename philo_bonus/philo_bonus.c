#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_set	*setting;
	t_ph	*philo;

	philo = NULL;
	if (ac != 5 && ac != 6)
		return (write(2, "error inavalid argement\n", 25), 1);
	setting = parsing(ac, av);
	if (setting == NULL)
		return (1);
	philo = loding_philo(setting);
	if (philo == NULL)
		return (1);
	if (run_process(philo, setting->nb_of_p))
		return (1);
}