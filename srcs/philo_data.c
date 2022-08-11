/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:23:21 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 15:36:13 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	push_back_list_second(t_table *l, int x, char **av, t_philo *element)
{
	element->philos = l;
	element->number = x;
	element->all = ft_atoi(av[1]);
	element->time2die = ft_atoi(av[2]);
	element->time2eat = ft_atoi(av[3]);
	element->time2sleep = ft_atoi(av[4]);
	element->compteur = -1;
	element->n_each_time = -2;
	element->timestart = gettime();
	element->last_meal = element->timestart;
	element->next = NULL;
	element->back = NULL;
	if (l->length == 0)
	{
		l->length = 0;
		l->dead = 0;
		l->begin = element;
		l->end = element;
	}
	return (0);
}

int	push_back_list(t_table *l, int x, char **av, int ac)
{
	t_philo	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (-1);
	push_back_list_second(l, x, av, element);
	if (ac == 6 && ft_atoi(av[5]) > 0)
	{
		element->n_each_time = ft_atoi(av[5]);
		element->compteur = 0;
	}
	if (l->length != 0)
	{
		l->dead = 0;
		l->end->next = element;
		element->back = l->end;
		l->end = element;
	}
	l->length++;
	return (0);
}

t_table	*new_dlist(void)
{
	t_table	*l;

	l = malloc(sizeof(*l));
	if (!l)
		return (NULL);
	l->begin = NULL;
	l->end = NULL;
	l->length = 0;
	l->dead = 0;
	if (pthread_mutex_init(&l->endphilo, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&l->print, NULL) != 0)
		return (NULL);
	return (l);
}

int	init_lst(t_table *arg, char **av, int ac)
{
	int	i;
	int	nb;

	nb = 1;
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		if (push_back_list(arg, nb, av, ac) == -1)
			return (-1);
		nb++;
		i++;
	}
	arg->begin->back = arg->end;
	arg->end->next = arg->begin;
	return (0);
}
