/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:05:26 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/14 00:32:45 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_init(t_philo *p, t_data *d)
{
	int		i;

	i = 1;
	if (pthread_mutex_init(&(d->pri), NULL) != 0)
		return (1);
	while (i <= d->number_of_philo)
	{
		if (pthread_mutex_init(&(p->fork), NULL) != 0)
			return (1);
		if (pthread_create(&(p->philo), NULL, routine, p) != 0)
			return (1);
		(p) = p->next;
		i++;
	}
	i = 1;
	while (i <= d->number_of_philo)
	{
		if (pthread_detach(p->philo) != 0)
			return (1);
		p = p->next;
		i++;
	}
	return (0);
}
