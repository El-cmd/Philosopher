/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:10:27 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 15:15:19 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo *element)
{
	if (exit_thread(element))
		return (1);
	lock(element);
	mutex_print(element, 1);
	pthread_mutex_lock(&element->n_time);
	element->last_meal = gettime();
	pthread_mutex_unlock(&element->n_time);
	mutex_print(element, 2);
	usleep_custom(element->time2eat);
	if (element->n_each_time > 0)
	{
		pthread_mutex_lock(&element->nb_eat);
		element->compteur++;
		pthread_mutex_unlock(&element->nb_eat);
	}
	unlock(element);
	return (0);
}

void	is_sleeping(t_philo *element)
{
	if (exit_thread(element) > 0)
		return ;
	if (element->n_each_time > 0 && each_time(element))
		return ;
	mutex_print(element, 3);
	usleep_custom(element->time2sleep);
}

void	is_thinking(t_philo *element)
{
	if (exit_thread(element) > 0)
		return ;
	if (element->n_each_time > 0 && each_time(element))
		return ;
	mutex_print(element, 4);
	usleep(((element->time2die - \
		(element->time2sleep + element->time2eat)) / 2) * 1000);
}

void	routine_norm(t_philo *tmp)
{
	take_fork(tmp);
	is_sleeping(tmp);
	is_thinking(tmp);
}

void	*routine(void *arg)
{
	t_philo		*tmp;
	long int	timenow;

	tmp = (t_philo *)arg;
	timenow = gettime();
	timenow = timenow - tmp->timestart;
	if (tmp->all == 1)
	{
		one_philo(tmp);
		return (0);
	}
	while (exit_thread(tmp) == 0)
	{
		if (tmp->n_each_time > 0)
		{
			while (each_time(tmp) != 1 && exit_thread(tmp) == 0)
				routine_norm(tmp);
		}
		else
			routine_norm(tmp);
	}
	return (0);
}
