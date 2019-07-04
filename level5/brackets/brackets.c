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

/*####################### PASSED IN EXAM ############################*/ 

#include <unistd.h>
# define BUFF_SIZE 2048

int is_valid_pair(char c, char d) // check if its a valid pair or not.
{
	return ((c == '(' && d == ')') || (c == '{' && d == '}') || (c == '[' && d == ']'));
}

int ft_brackets (char *str)
{
	int j = 0;
	int stack[BUFF_SIZE]; // int array stack implemantation used for push and pop operation
	int position = 0; // initial position of the top of the stack 
	while (str[j])
	{
		if (str[j]== '(' || str[j] == '{' || str[j] == '[') // push operation to check the opening bracket
			stack[++position] = str[j];
		if (str[j]== ')' || str[j] == '}' || str[j] == ']') // operation to check the closing bracket
			if (!(is_valid_pair(stack[position--], str[j]))) // check if the pair is valid or not 
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


