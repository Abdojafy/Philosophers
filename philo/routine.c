/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:35:48 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/13 22:56:10 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ph)
{
	t_philo	*p;

	p = (t_philo *) ph;
	if (p->id % 2 == 0)
		ft_sleep(p, p->data->time_to_eat);
	while (1)
	{
		pthread_mutex_lock(&(p->fork));
		ft_print_message(p, "has taken a fork");
		pthread_mutex_lock(&(p->next->fork));
		ft_print_message(p, "has taken a fork");
		ft_print_message(p, "is eating");
		p->time_last_eat = ft_gettime(p->data->launch_time);
		ft_sleep(p, p->data->time_to_eat);
		p->number_of_eat++;
		pthread_mutex_unlock(&(p->next->fork));
		pthread_mutex_unlock(&(p->fork));
		ft_print_message(p, "is sleeping");
		ft_sleep(p, p->data->time_to_sleep);
		ft_print_message(p, "is thinking");
	}	
	return ((void *)1);
}
