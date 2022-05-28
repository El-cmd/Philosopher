/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:00:52 by vloth             #+#    #+#             */
/*   Updated: 2022/05/28 03:55:11 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int main(int ac, char **av)
{
	t_table *philos;

	philos = new_dlist();
	printf("1\n");
	init_lst(philos, av);
	printf("2\n");
	init_mutex(philos);
	printf("3\n");
	init_thread(philos);
	destroy_mutex(philos);
	printf("le noombre de philo est de %d\n", philos->length);
	return 0;
}