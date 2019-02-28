/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:53:11 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/28 00:41:05 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
void ft_prime(int nbr)
{
	int i = 1;
	if (nbr == 1)
	{
		printf("1");
	}
	while (nbr >= ++i)
	{
		if (nbr % i == 0)
		{
			printf("%d", i);
			if (nbr == i)
				break;
			printf("*");
			nbr /= i;
			i = 1;
		}
	}
}
int main (int ac, char **av)
{
	if (ac == 2)
	{
		ft_prime(atoi(av[1]));
	}
	printf("\n");
	return (0);
}
