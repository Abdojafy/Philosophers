/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:58:16 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/14 02:22:51 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_destroy(t_philo *p, t_data *d)
{
	int		i;
	t_philo	*temp;

	i = 1;
	while (i <= d->number_of_philo)
	{
		if (pthread_mutex_destroy(&(p->fork)) != 0)
			return (1);
		temp = p->next;
		free (p);
		p = temp;
		i++;
	}
	if (pthread_mutex_destroy(&(d->pri)) != 0)
		return (1);
	free (d);
	return (0);
}
