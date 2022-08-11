/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:55:50 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 16:32:40 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	mutex_print(t_philo *element, int x)
{
	if (x == 5)
	{
		pthread_mutex_lock(&element->philos->print);
		printf(RED"%ld %d died\n"RESET, gettime() - element->timestart, \
			element->number);
		pthread_mutex_unlock(&element->philos->print);
		return (0);
	}
	else if (exit_thread(element))
		return (-1);
	pthread_mutex_lock(&element->philos->print);
	if (x == 1 || x == 2)
		print_fork_dead(element, x);
	else if (x == 3)
		printf(MAG"%ld %d is sleeping\n"RESET, gettime() - element->timestart, \
			element->number);
	else if (x == 4)
		printf(BLU"%ld %d is thinking\n"RESET, gettime() - element->timestart, \
			element->number);
	pthread_mutex_unlock(&element->philos->print);
	return (0);
}

void	print_fork_dead(t_philo *element, int x)
{
	if (x == 1)
	{
		printf(GRN"%ld %d has taken a fork\n"RESET, \
				gettime() - element->timestart, element->number);
		printf(GRN"%ld %d has taken a fork\n"RESET, \
				gettime() - element->timestart, element->number);
	}
	else if (x == 2)
		printf(YEL"%ld %d is eating\n"RESET, gettime() - element->timestart, \
			element->number);
}
