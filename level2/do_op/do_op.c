/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 23:24:00 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/18 23:43:22 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_do_op(int a, int b, char c)
{
	if (c == '*')
		return (a * b);
	else if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '/')
		return (a / b);
	else if (c == '%')
		return (a % b);
	return (0);
}


int main (int ac, char **av)
{
	if(ac == 4)
	{
		printf("%d\n", ft_do_op(atoi(av[1]), atoi(av[3]), av[2][0]));
	}
	else
		write(1, "\n", 1);
	return (0);
}
