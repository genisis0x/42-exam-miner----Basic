/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:25:16 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/06 18:26:14 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_putnbr(int a)
{
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putchar((a % 10) + '0');
	}
	else
		ft_putchar(a + '0');
}

int main (int ac, char **av)
{
	if (ac >= 1 && av[0] >= 0)
	{
		ft_putnbr(--ac);
	}
	write(1, "\n", 1);
	return (0);
}

