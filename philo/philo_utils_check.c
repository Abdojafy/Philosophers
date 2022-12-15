/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:43:56 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/13 23:01:02 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_eat(t_philo *p, t_data *d)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= d->number_of_philo)
	{
		if (p->number_of_eat >= d->number_to_eat)
			j++;
		p = p->next;
		i++;
	}
	return (j);
}

int	ft_check_die(t_philo *p, t_data *d)
{
	while (1)
	{
		if (d->number_to_eat != -1)
			if (ft_check_eat(p, d) == d->number_of_philo)
				return (1);
		if ((ft_gettime(d->launch_time) - p->time_last_eat) >= d->time_to_die)
		{
			printf("%ld  %d died\n", ft_gettime(d->launch_time), p->id);
			pthread_mutex_lock(&(p->data->pri));
			return (1);
		}
		p = p->next;
		usleep(500);
	}
	return (0);
}
