/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:36:35 by vloth             #+#    #+#             */
/*   Updated: 2022/05/28 04:06:02 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	rip_philo(t_philo *element)
{
	if ((gettime() - element->timestart) > element->time2die)
		return 1;
	return(0);
}


void	init_mutex(t_table *element)
{
	t_philo *tmp;
	tmp = element->begin;
	int i;

	i = 0;
	while (i < element->length)
	{
		if (pthread_mutex_init(&tmp->fork, NULL) != 0)
			return ;
		tmp = tmp->next;
		i++;
	}
}

void	destroy_mutex(t_table *element)
{
	t_philo *tmp;
	int i;

	i = 0;
	tmp = element->begin;
	while (i < element->length)
	{
		if (pthread_mutex_destroy(&tmp->fork) != 0)
			return ;
		tmp = tmp->next;
	}
}

void	take_fork(t_philo *element)
{
	pthread_mutex_lock(&element->fork);
	pthread_mutex_lock(&element->back->fork);
	if (element->left_fork == 1 && element->back->left_fork == 1)
	{
		element->left_fork--;
		element->back->left_fork--;
		printf("%ld %d has taken a fork\n", gettime() - element->timestart, element->number);
		printf("%ld %d has taken a fork\n", gettime() - element->timestart, element->number);
		philo_eat(element);
	}
	pthread_mutex_unlock(&element->fork);
	pthread_mutex_unlock(&element->back->fork);
}

void	philo_eat(t_philo *element)
{
	if (element->left_fork == 0 && element->back->left_fork == 0)
	{
		printf("%ld %d is eating\n", gettime() - element->timestart, element->number);
		element->left_fork++;
		element->back->left_fork++;
		usleep(element->time2eat * 1000);
	}
}