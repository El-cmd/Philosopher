/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:17:11 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 16:34:51 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_even_thread(t_table *table)
{
	t_philo	*tmp;
	int		i;

	i = 0;
	tmp = table->begin;
	while (i < table->length)
	{
		if (pthread_create(&tmp->philo, NULL, &routine, (void *)tmp) != 0)
			return (-1);
		tmp = tmp->next->next;
		i += 2;
	}
	return (0);
}

int	init_odd_thread(t_table *table)
{
	t_philo	*tmp;
	int		i;

	i = 1;
	tmp = table->begin->next;
	while (i < table->length)
	{
		if (pthread_create(&tmp->philo, NULL, &routine, (void *)tmp) != 0)
			return (-1);
		tmp = tmp->next->next;
		i += 2;
	}
	return (0);
}

int	init_thread(t_table *table)
{
	t_philo	*tmp;

	tmp = table->begin;
	if (init_even_thread(table) == -1)
		return (-1);
	usleep(50);
	if (init_odd_thread(table) == -1)
		return (-1);
	while (1)
	{
		if (exit_thread(tmp))
		{
			mutex_print(tmp, 5);
			finish(table);
			return (0);
		}
		else if (tmp->n_each_time > 0 && each_time(tmp))
		{
			finish(table);
			return (0);
		}
		tmp = tmp->next;
		usleep(10);
	}
	return (0);
}

void	finish(t_table *table)
{
	int		i;
	t_philo	*tmp;

	tmp = table->begin;
	i = 0;
	while (i < table->length)
	{
		if (pthread_join(tmp->philo, NULL) != 0)
			return ;
		tmp = tmp->next;
		i++;
	}
	if (tmp->n_each_time > 0 && each_time(tmp))
	{
		pthread_mutex_lock(&tmp->philos->print);
		printf(RED"ALL PHILOS HAVE BEEN EATING: END OF SIMULATION\n"RESET);
		pthread_mutex_unlock(&tmp->philos->print);
	}
}
