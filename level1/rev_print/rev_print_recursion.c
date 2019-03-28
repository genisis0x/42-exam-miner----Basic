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

/*************************************************Not good solution but just a practice of recursion in a base question****************/

#include <unistd.h>
#include <stdio.h>

void swap(char *a, char *b) // swap function for swaping the char
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_print(char *str, int start, int end) // driver function
{
	if (start > end) // when condition fails print the whole string.  
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
	else
	{
		swap(&str[start++], &str[end--]); // swap start and end and move forward
		ft_print(str, start, end); // call recursively the function and move to the next index.
	}
}

int ft_strlen(char *str) // length of string
{
	int i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
int main (int ac, char **av) // main driver
{
	if (ac == 2)
	{
		ft_print(av[1], 0, (ft_strlen(av[1]) - 1));
	}
	return 0;
}
