/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:49:51 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/13 22:54:44 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

time_t	ft_gettimeoflaunch(void)
{
	struct timeval	launch_time;

	gettimeofday(&launch_time, NULL);
	return (((launch_time.tv_sec * 1000) + (launch_time.tv_usec / 1000)));
}

t_data	*ft_lstnew_data(int *tab, time_t time, t_data **alst)
{
	t_data	*newlst_data;

	newlst_data = (t_data *) malloc(sizeof(t_data));
	if (!newlst_data)
		return (NULL);
	newlst_data->number_to_eat = tab[4];
	newlst_data->number_of_philo = tab[0];
	newlst_data->time_to_eat = (tab[2]);
	newlst_data->time_to_die = (tab[1]);
	newlst_data->time_to_sleep = (tab[3]);
	newlst_data->launch_time = time;
	if (!*alst)
		*alst = newlst_data;
	return (newlst_data);
}

t_philo	*ft_lstnew_philo(int id, int *tab, t_philo *next, t_data *d)
{
	t_philo	*newlst_philo;

	newlst_philo = (t_philo *) malloc(sizeof(t_philo));
	if (!newlst_philo)
		return (NULL);
	newlst_philo->id = id;
	newlst_philo->data = d;
	newlst_philo->number_of_eat = 0;
	newlst_philo->next = next;
	if (tab[0] == 1)
		newlst_philo->next = newlst_philo;
	return (newlst_philo);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*lst;

	if (!*alst)
		*alst = new;
	else
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
	}
}
