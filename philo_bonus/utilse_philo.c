/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:57:57 by bikourar          #+#    #+#             */
/*   Updated: 2024/10/17 12:37:10 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	white_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static char	*ft_strdup(char const *src)
{
	char	*destion;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	destion = (char *)malloc(ft_strlen(src) + 1);
	if (!destion)
		return (NULL);
	while (src[i])
		destion[j++] = src[i++];
	destion[j] = '\0';
	return (destion);
}

int	ft_atoi(const char *str)
{
	long long	res;
	char		*nub;
	int			i;

	i = 0;
	res = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (-1);
	nub = ft_strdup(str);
	i = 0;
	while (nub[i])
	{
		res = (res * 10) + (nub[i] - 48);
		if (res > INT_MAX)
			return (free(nub), -1);
		i++;
	}
	return (free(nub), res);
}
