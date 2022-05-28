/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:23:21 by vloth             #+#    #+#             */
/*   Updated: 2022/05/28 04:09:14 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	push_back_list(t_table *l, int x, char **av)
{
	t_philo	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return ;
	element->number = x;
	element->time2die = ft_atoi(av[2]);
	element->time2eat = ft_atoi(av[3]);
	element->time2sleep = ft_atoi(av[4]);
	element->timestart = gettime();
	element->left_fork = 1;
	element->next = NULL;
	element->back = NULL;
	if (l->length == 0)
	{
		l->length = 0;
		l->begin = element;
		l->end = element;
	}
	else
	{
		l->end->next = element;
		element->back = l->end;
		l->end = element;
	}
	l->length++;
}

t_table	*new_dlist(void)
{
	t_table	*l;
	l = malloc(sizeof(*l));
	l->begin  = NULL;
	l->end = NULL;
	l->length = 0;
	return (l);
}

void	init_lst(t_table *arg, char **av)
{
	int i = 0;
	int	nb = 1;
	while (i < ft_atoi(av[1]))
	{
		push_back_list(arg, nb, av);
		nb++;
		i++;
	}
	arg->begin->back = arg->end;
	arg->end->next = arg->begin;
}

void *routine(void *arg)
{
	t_philo *tmp = (t_philo *)arg;
	long int timenow;

	timenow = gettime();
	timenow = timenow - tmp->timestart;
	//printf("%ld %d taken a fork\n", timenow, tmp->number);
	//take_fork(tmp);
	while (rip_philo(tmp) != 1)
	{
		take_fork(tmp);
	}
	if (rip_philo(tmp) == 1)
	{
		timenow = gettime() - tmp->timestart;
		printf("%ld %d died\n", timenow, tmp->number);
	}
	return 0;
}		

void init_thread(t_table *table)
{
	t_philo *tmp;
	int i;

	i = 0;
	tmp = table->begin;
	while (i < table->length)
		{
			pthread_create(&tmp->philo, NULL, &routine, (void *)tmp);
			tmp = tmp->next;
			i++;
		}
	tmp = table->begin;
	i = 0;
	while (i < table->length)
	{
		pthread_join(tmp->philo, NULL);
		tmp = tmp->next;
		i++;
	}
	return ;
}