/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:00:52 by vloth             #+#    #+#             */
/*   Updated: 2022/08/05 01:20:02 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_table	*philos;

	if (error_gestion(av, ac) == 0)
		return (0);
	philos = new_dlist();
	if (!philos)
		return (-1);
	if (init_lst(philos, av, ac) == -1)
		return (-1);
	if (init_mutex(philos) == -1)
		return (-1);
	if (init_thread(philos) == -1)
		return (-1);
	if (destroy_mutex(philos) == -1)
		return (-1);
	free_list(philos);
	free(philos);
	return (0);
}
