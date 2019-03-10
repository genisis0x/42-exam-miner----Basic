/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:14:14 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/09 16:39:34 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_print(char *str, int start, int end)
{
	if (start == end || start - end == 1)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
	else
	{
		swap(&str[start++], &str[end--]);
		ft_print(str, start, end);
	}
}

int ft_strlen(char *str)
{
	int i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
int main (int ac, char **av)
{
	if (ac == 2)
	{
		ft_print(av[1], 0, (ft_strlen(av[1]) - 1));
	}
	return 0;
}
