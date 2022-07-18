/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:29:03 by vloth             #+#    #+#             */
/*   Updated: 2022/07/18 17:37:21 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_sleeping(t_philo *element)
{

	pthread_mutex_lock(&element->think);
	pthread_mutex_lock(&element->sleep);
	if (element->go_sleep == 1 && exit_thread(element) != 1 && rip_philo(element) != 1)
	{
		printf("%ld %d is sleeping\n", gettime() - element->timestart, element->number);
		usleep(element->time2sleep * 1000);
		element->go_sleep = 0;
		element->go_think = 1;
		program_end(element);
	}
	pthread_mutex_unlock(&element->sleep);
	pthread_mutex_unlock(&element->think);
}

void	is_thinking(t_philo *element)
{
	exit_thread(element);
	program_end(element);
	pthread_mutex_lock(&element->think);
	if (element->go_think == 1 && exit_thread(element) != 1)
	{
		printf("%ld %d is thinking\n", gettime() - element->timestart, element->number);
		usleep(((element->time2die - (element->time2sleep + element->time2eat)) / 2) * 1000);
		element->go_think = 0;
	}
	pthread_mutex_unlock(&element->think);
}

void	one_philo(t_philo *element)
{
	if (element->all == 1)
	{
		printf("%ld %d has taken a fork\n", gettime() - element->timestart, element->number);
		usleep(element->time2die * 1000);
		printf("%ld %d died\n", (gettime() - element->timestart), element->number);
		exit(1);
	}
}

//int	each_time_