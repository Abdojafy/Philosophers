/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:38:14 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/13 22:58:40 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

time_t	ft_gettime(time_t launch_time)
{
	struct timeval	routine_time;
	time_t			time;

	gettimeofday(&routine_time, NULL);
	time = ((routine_time.tv_sec * 1000) + (routine_time.tv_usec / 1000));
	return (time - launch_time);
}

void	ft_print_message(t_philo *p, char *str)
{
	pthread_mutex_lock(&(p->data->pri));
	printf("%ld %d %s\n", ft_gettime(p->data->launch_time), p->id, str);
	pthread_mutex_unlock(&(p->data->pri));
}

void	ft_sleep(t_philo *p, time_t time)
{
	time_t	start_time;

	start_time = ft_gettime(p->data->launch_time);
	while (ft_gettime(p->data->launch_time) - start_time < time)
		usleep(100);
}
