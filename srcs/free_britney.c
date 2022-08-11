/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_britney.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:22:06 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 15:23:06 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*pop_front_list(t_table *table)
{
	t_philo	*tmp;

	if (table->length > 1)
	{
		tmp = table->begin;
		table->begin = table->begin->next;
		table->begin->back = NULL;
		table->length--;
		free(tmp);
	}
	else
	{
		tmp = table->begin;
		table->begin = NULL;
		table->end = NULL;
		table->length = 0;
		free(tmp);
	}
	return (tmp);
}

void	free_list(t_table *table)
{
	t_philo	*tmp;

	tmp = table->begin;
	while (tmp != NULL)
	{
		tmp = pop_front_list(table);
		tmp = table->begin;
	}
}
