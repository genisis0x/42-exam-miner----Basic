/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:15:17 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/23 01:43:33 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
# define BUFF_SIZE 2048

int is_pair(char c, char d)
{
	return ((c == '(' && d == ')') || (c == '{' && d == '}') || (c == '[' && d == ']'));
}

int ft_brackets (char *str)
{
	int j = 0;
	int stack[BUFF_SIZE];
	int position = 0;
	while (str[j])
	{
		if (str[j]== '(' || str[j] == '{' || str[j] == '[')
			stack[++position] = str[j];
		if (str[j]== ')' || str[j] == '}' || str[j] == ']')
			if (!(is_pair(stack[position--], str[j])))
				return (0);
		j++;
	}
	return (!position);
}

int main (int ac, char **av)
{
	int i = 1;

	if (ac == 1)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (ac > i)
	{
		if (ft_brackets(av[i]))
		{
			write (1, "OK\n", 3);
		}
		else
			write (1, "Error\n", 6);
		i++;
	}
	return (0);
}


