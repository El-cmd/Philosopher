/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:07:23 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 15:15:42 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	j;

	j = 0;
	i = 0;
	n = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		j = j * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * j);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

long int	gettime(void)
{
	struct timeval	current_time;
	long int		time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	one_philo(t_philo *element)
{
	if (element->all == 1)
	{
		pthread_mutex_lock(&element->philos->print);
		printf("%ld %d has taken a fork\n", gettime() \
			- element->timestart, element->number);
		usleep(element->time2die * 1000);
		pthread_mutex_unlock(&element->philos->print);
		return ;
	}
}
