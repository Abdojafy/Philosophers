/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:56:28 by ajafy             #+#    #+#             */
/*   Updated: 2022/12/11 23:59:17 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_atoi(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (str[i] || res > 2147483647 || res == 0)
		return (-1);
	return ((int)res);
}

int	ft_check_args(int ac, char *av[], int *tab)
{
	int	i;

	if (ac != 6 && ac != 5)
		return (printf("Le nombre des arguments est incorrecte !"), -1);
	i = 1;
	while (i < ac)
	{
		tab[i - 1] = ft_atoi(av[i]);
		if (tab[i - 1] == -1)
			return (printf("Erreur, Veuillez entrer que des entiers!"), -1);
		i++;
	}
	if (ac == 5)
		tab[4] = -1;
	return (0);
}
