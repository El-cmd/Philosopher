/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:00:52 by vloth             #+#    #+#             */
/*   Updated: 2022/05/30 11:33:52 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int main(int ac, char **av)
{
	t_table *philos;

	philos = new_dlist();
	init_lst(philos, av);
	init_mutex(philos);
	init_thread(philos);
	destroy_mutex(philos);
	return 0;
}