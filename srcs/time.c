/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:36:35 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 15:59:26 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	rip_philo(t_philo *element)
{
	long int	start;

	start = gettime();
	if ((start - element->last_meal) >= element->time2die)
		return (1);
	return (0);
}

void	program_end(t_philo *element)
{
	if (rip_philo(element))
	{
		element->philos->dead = 1;
		return ;
	}
}

int	exit_thread(t_philo *element)
{
	pthread_mutex_lock(&element->n_time);
	pthread_mutex_lock(&element->philos->endphilo);
	program_end(element);
	if (element->philos->dead == 1)
	{
		pthread_mutex_unlock(&element->philos->endphilo);
		pthread_mutex_unlock(&element->n_time);
		return (element->number);
	}
	else
	{
		pthread_mutex_unlock(&element->n_time);
		pthread_mutex_unlock(&element->philos->endphilo);
		return (0);
	}
}

void	usleep_custom(long int time)
{
	long int	start;
	long int	actual_time;
	long int	end;

	start = gettime();
	end = start + time;
	actual_time = gettime();
	while (actual_time <= end)
	{
		actual_time = gettime();
		usleep(10);
	}
}

int	each_time(t_philo *element)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < element->all)
	{
		pthread_mutex_lock(&element->nb_eat);
		if (element->compteur >= element->n_each_time && \
			element->compteur > 0 \
			&& element->n_each_time > 0)
			n++;
		pthread_mutex_unlock(&element->nb_eat);
		i++;
		element = element->next;
	}
	if (n == i)
		return (1);
	return (0);
}
