/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:01:07 by vloth             #+#    #+#             */
/*   Updated: 2022/08/11 16:10:58 by vloth            ###   ########.fr       */
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

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define RESET "\e[0m"

/* Double liste */
typedef struct t_table
{
	int				length;
	pthread_mutex_t	endphilo;
	pthread_mutex_t	print;
	int				dead;
	struct t_philo	*begin;
	struct t_philo	*end;

}					t_table;

/* Maillon de la liste*/
typedef struct t_philo
{
	int				all;
	int				number;
	pthread_t		philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	n_time;
	pthread_mutex_t	nb_eat;
	int				n_each_time;
	int				compteur;
	long int		last_meal;
	long int		timestart;
	int				time2die;
	int				time2sleep;
	int				time2eat;
	t_table			*philos;
	struct t_philo	*back;
	struct t_philo	*next;
}				t_philo;

			/* Utils */
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
long	int	gettime(void);
void	one_philo(t_philo *element);

			/* Init thread*/
int		init_thread(t_table *table);
void	finish(t_table *table);

			/* Routine */
int		take_fork(t_philo *element);
void	is_sleeping(t_philo *element);
void	is_thinking(t_philo *element);
void	*routine(void *arg);

			/* Mutex */
void	lock(t_philo *element);
void	unlock(t_philo *element);
int		init_mutex(t_table *element);
int		destroy_mutex(t_table *element);

			/* Init datas */
int		push_back_list(t_table *l, int x, char **av, int ac);
t_table	*new_dlist(void);
int		init_lst(t_table *arg, char **av, int ac);

			/* Free */
void	free_list(t_table *table);
t_philo	*pop_front_list(t_table *table);

			/* End */
int		rip_philo(t_philo *element);
int		exit_thread(t_philo *element);
void	program_end(t_philo *element);
int		each_time(t_philo *element);
void	usleep_custom(long int time);

			/* Print */
int		mutex_print(t_philo *element, int x);
void	print_fork_dead(t_philo *element, int x);

			/* Error */
int		error_gestion(char **av, int ac);

#endif