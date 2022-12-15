/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:22:00 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/14 02:23:22 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int ac, char *av[])
{
	t_data	*d;
	t_philo	*p;
	int		tab[5];

	if (ft_check_args (ac, av, tab) == -1)
		return (1);
	d = ft_remplire_t_data(tab);
	p = ft_remplire_t_philo(tab, d);
	if (ft_init(p, d) == 1)
		return (1);
	while (1)
	{
		if (ft_check_die(p, d))
			break ;
	}
	if (ft_destroy(p, d) == 1)
		return (1);
}
