/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:29:03 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 13:41:58 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lock(t_philo *element)
{
	if (element->number % 2 == 0)
	{
		pthread_mutex_lock(&element->fork);
		pthread_mutex_lock(&element->back->fork);
	}
	else
	{
		pthread_mutex_lock(&element->back->fork);
		pthread_mutex_lock(&element->fork);
	}
}

void	unlock(t_philo *element)
{
	if (element->number % 2 == 0)
	{
		pthread_mutex_unlock(&element->fork);
		pthread_mutex_unlock(&element->back->fork);
	}
	else
	{
		pthread_mutex_unlock(&element->back->fork);
		pthread_mutex_unlock(&element->fork);
	}
}

int	init_mutex(t_table *element)
{
	t_philo	*tmp;
	int		i;

	tmp = element->begin;
	i = 0;
	while (i < element->length)
	{
		if (pthread_mutex_init(&tmp->fork, NULL) != 0)
			return (-1);
		if (pthread_mutex_init(&tmp->n_time, NULL) != 0)
			return (-1);
		if (pthread_mutex_init(&tmp->nb_eat, NULL) != 0)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	destroy_mutex(t_table *element)
{
	t_philo	*tmp;
	int		i;

	i = 0;
	tmp = element->begin;
	if (pthread_mutex_destroy(&element->endphilo) != 0)
		return (-1);
	if (pthread_mutex_destroy(&element->print) != 0)
		return (-1);
	while (i < element->length)
	{
		if (pthread_mutex_destroy(&tmp->fork) != 0)
			return (-1);
		if (pthread_mutex_destroy(&tmp->n_time) != 0)
			return (-1);
		if (pthread_mutex_destroy(&tmp->nb_eat) != 0)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
