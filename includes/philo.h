/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:01:07 by vloth             #+#    #+#             */
/*   Updated: 2022/07/19 14:34:50 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

/* Maillon de la liste*/
typedef struct t_philo
{
	int all;
	int	number;
	pthread_t philo;
	pthread_mutex_t fork;
	pthread_mutex_t endphilo;
	pthread_mutex_t sleep;
	pthread_mutex_t think;
	pthread_mutex_t n_time;
	int	n_each_time;
	int compteur;
	int	go_think;
	long int last_meal;
	int	left_fork;
	int	end;
	int	go_sleep;
	long int timestart;
	int		time2die;
	int		time2sleep;
	int		time2eat;
	struct t_philo *back;
	struct t_philo *next;
}				t_philo;


/* Double liste */
typedef struct t_table
{
	int	length;
	struct t_philo *begin;
	struct t_philo *end;

} 				t_table;
/* Utils */

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

/* Init */
void	push_back_list(t_table *l, int x, char **av, int ac);
t_table	*new_dlist(void);
void	init_lst(t_table *arg, char **av, int ac);
void	init_thread(t_table *table);
void	*routine(void *);
long int gettime(void);
int		rip_philo(t_philo *element);
void	init_mutex(t_table *element);
void	destroy_mutex(t_table *element);
void	philo_eat(t_philo *element);
void	take_fork(t_philo *element);
int		exit_thread(t_philo *element);
void	program_end(t_philo *element);
void 	is_sleeping(t_philo *element);
void	is_thinking(t_philo *element);
void	one_philo(t_philo *element);
int		error_gestion(char **av, int ac);
int		each_time(t_philo *element);
void	lock(t_philo *element);
void	unlock(t_philo *element);

#endif