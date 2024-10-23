#include "philo_bonus.c"

void	add_back(t_ph **lst, t_ph *new)
{
	t_ph	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}