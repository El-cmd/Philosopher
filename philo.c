/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:00:52 by vloth             #+#    #+#             */
/*   Updated: 2022/07/11 16:27:50 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int main(int ac, char **av)
{
	t_table *philos;
	
	if (ac == 0)
		return 0;
	philos = new_dlist();
	init_lst(philos, av);
	init_mutex(philos);
	init_thread(philos);
	destroy_mutex(philos);
	return 0;
}