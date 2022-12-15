/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:19:58 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/13 22:53:44 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_remplire_t_philo(int tab[], t_data *d)
{
	int		i;
	t_philo	*pnext;
	t_philo	*p;

	i = 1;
	p = NULL;
	while (i <= tab[0])
	{
		pnext = NULL;
		if (i == tab[0])
			pnext = p;
		ft_lstadd_back(&p, ft_lstnew_philo(i, tab, pnext, d));
		i++;
	}
	return (p);
}

t_data	*ft_remplire_t_data(int tab[])
{
	t_data	*d;
	time_t	start;

	d = NULL;
	start = ft_gettimeoflaunch();
	d = ft_lstnew_data(tab, start, &d);
	return (d);
}
