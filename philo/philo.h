/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:33:26 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/13 22:57:53 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>
# include<sys/time.h>
# include<unistd.h>

typedef struct s_data
{
	pthread_mutex_t	pri;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_to_eat;
	time_t			launch_time;
	int				number_of_philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	pthread_mutex_t	fork;
	int				time_last_eat;
	int				number_of_eat;
	t_data			*data;
	struct s_philo	*next;
}	t_philo;

t_philo		*ft_lstnew_philo(int id, int *tab, t_philo *next, t_data *d);
t_data		*ft_lstnew_data(int *tab, time_t time, t_data **alst);
void		ft_lstadd_back(t_philo **alst, t_philo *new);
t_philo		*ft_lstlast(t_philo *lst);
void		*routine(void *id);
int			ft_check_args(int ac, char *av[], int *tab);
int			ft_atoi(char *str);
void		ft_create(t_philo	*p, t_philo	*pnext);
//void		ft_remplir_list(int	*tab);
t_philo		*ft_remplire_t_philo(int tab[], t_data *d);
void		*routine(void *ph);
void		ft_sleep(t_philo *p, time_t time);
void		ft_print_message(t_philo *p, char *str);
time_t		ft_gettime(time_t launch_time);
int			ft_check_die(t_philo *p, t_data *d);
int			ft_check_eat(t_philo *p, t_data *d);
int			ft_destroy(t_philo *p, t_data *d);
int			ft_init(t_philo *p1, t_data *d1);
t_data		*ft_remplire_t_data(int tab[]);
time_t		ft_gettimeoflaunch(void);

#endif