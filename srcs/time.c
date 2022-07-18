/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:36:35 by vloth             #+#    #+#             */
/*   Updated: 2022/07/18 14:30:08 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	rip_philo(t_philo *element)
{
	long int start;
	start = gettime();
	if ((start - element->last_meal) >= element->time2die)
		return 1;
	return(0);
}

void	program_end(t_philo *element)
{
	if (exit_thread(element) == 2)
		exit(1);
	pthread_mutex_lock(&element->endphilo);
	if (rip_philo(element))
	{
		element->end = 1;
		printf("%ld %d died\n", (gettime() - element->timestart), element->number);
		pthread_mutex_unlock(&element->endphilo);
		exit(1);
	}
	pthread_mutex_unlock(&element->endphilo);
}

int	exit_thread(t_philo *element)
{
	int i = 0;
	if (each_time(element) == 1)
		return 2;
	while (i <= element->all)
	{
		pthread_mutex_lock(&element->endphilo);
		if (element->end == 1)
		{
			pthread_mutex_unlock(&element->endphilo);
			return 1;
		}
		pthread_mutex_unlock(&element->endphilo);
		i++;
		element = element->next;
	}
	return 0;
}

void	init_mutex(t_table *element)
{
	t_philo *tmp;
	tmp = element->begin;
	int i;

	i = 0;
	while (i <= element->length)
	{
		if (pthread_mutex_init(&tmp->endphilo, NULL) != 0)
			return ;
		if (pthread_mutex_init(&tmp->fork, NULL) != 0)
			return ;
		if (pthread_mutex_init(&tmp->sleep, NULL) != 0)
			return ;
		if (pthread_mutex_init(&tmp->think, NULL) != 0)
			return ;
		if (pthread_mutex_init(&tmp->n_time, NULL) != 0)
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
	while (i <= element->length)
	{
		if (pthread_mutex_destroy(&tmp->endphilo) != 0)
			return ;
		if (pthread_mutex_destroy(&tmp->fork) != 0)
			return ;
		if (pthread_mutex_destroy(&tmp->sleep) != 0)
			return ;
		if (pthread_mutex_destroy(&tmp->sleep) != 0)
			return ;
		if (pthread_mutex_destroy(&tmp->n_time) != 0)
			return ;
		tmp = tmp->next;
		i++;
	}
}

void	take_fork(t_philo *element)
{
	pthread_mutex_lock(&element->sleep);
	pthread_mutex_lock(&element->fork);
	pthread_mutex_lock(&element->back->fork);
	if (exit_thread(element) == 1)
		program_end(element);
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
	pthread_mutex_unlock(&element->sleep);
}

void	philo_eat(t_philo *element)
{
	if (exit_thread(element) == 1)
		program_end(element);
	if (element->left_fork == 0 && element->back->left_fork == 0)
	{
		printf("%ld %d is eating\n", gettime() - element->timestart, element->number);
		element->last_meal = gettime();
		element->left_fork++;
		element->back->left_fork++;
		pthread_mutex_lock(&element->n_time);
		if (element->n_each_time != -2)
			element->compteur ++;
		pthread_mutex_unlock(&element->n_time);
		usleep(element->time2eat * 1000);
		element->go_sleep = 1;
	}
}
