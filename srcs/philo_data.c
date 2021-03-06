/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:23:21 by vloth             #+#    #+#             */
/*   Updated: 2022/07/18 18:52:38 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	push_back_list(t_table *l, int x, char **av, int ac)
{
	t_philo	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return ;
	element->number = x;
	element->all = ft_atoi(av[1]);
	element->time2die = ft_atoi(av[2]);
	element->time2eat = ft_atoi(av[3]);
	element->time2sleep = ft_atoi(av[4]);
	element->compteur = -1;
	element->n_each_time = -2;
	if (ac == 6 && ft_atoi(av[5]) > 0)
	{
		element->n_each_time = ft_atoi(av[5]);
		element->compteur = 0;
	}
	element->timestart = gettime();
	element->last_meal = element->timestart;
	element->left_fork = 1;
	element->end = 0;
	element->go_sleep = 0;
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

void	init_lst(t_table *arg, char **av, int ac)
{
	int i = 0;
	int	nb = 1;
	while (i < ft_atoi(av[1]))
	{
		push_back_list(arg, nb, av, ac);
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
	if (tmp->all == 1)
	{
		one_philo(tmp);
		return 0;
	}
	while (exit_thread(tmp) != 1 || exit_thread(tmp) != 2)
	{
		program_end(tmp);
		take_fork(tmp);
		is_sleeping(tmp);
		is_thinking(tmp);
	}
	return 0;
}		

void	init_even_thread(t_table *table)
{
	t_philo *tmp;
	int i;

	i = 1;
	tmp = table->begin->next;
	while (i < table->length)
	{
		pthread_create(&tmp->philo, NULL, &routine, (void *)tmp);
		tmp = tmp->next->next;
		i += 2;
	}
}

void	init_odd_thread(t_table *table)
{
	t_philo *tmp;
	int i;

	i = 0;
	tmp = table->begin;
	while (i < table->length)
	{
		pthread_create(&tmp->philo, NULL, &routine, (void *)tmp);
		tmp = tmp->next->next;
		i += 2;
	}
}

void init_thread(t_table *table)
{
	t_philo *tmp;
	int i;

	init_even_thread(table);
	usleep(100);
	init_odd_thread(table);
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
