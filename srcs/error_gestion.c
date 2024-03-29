/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:44:09 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 15:59:36 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_digit(int nb)
{
	if (nb >= 48 && nb <= 57)
		return (1);
	return (0);
}

int	check_arg(char **av, int ac)
{
	int	i;
	int	n;

	i = 1;
	while (i < ac)
	{
		n = 0;
		while (av[i][n])
		{
			if (!is_digit(av[i][n]))
			{
				printf("Error: use only digit caracters.\n");
				return (0);
			}
			n++;
		}
		i++;
	}
	return (1);
}

int	check_overflow(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_strlen(av[i]) > 11)
		{
			printf("Error: int overflow.\n");
			return (0);
		}
		if (ft_atoi(av[i]) < 1)
		{
			printf("Error: You use negative numbers.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	error_gestion(char **av, int ac)
{
	if (check_arg(av, ac) == 0 || check_overflow(av, ac) == 0)
		return (0);
	else if (ac != 5 && ac != 6)
	{
		printf("Error: a parameter is missing\n");
		return (0);
	}
	return (1);
}
