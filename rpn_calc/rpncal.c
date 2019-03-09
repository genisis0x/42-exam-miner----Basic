/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpncal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:33:22 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/08 20:56:38 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define STK_SIZE 2048
#include <stdlib.h>

int top = -1;
int stack[STK_SIZE];

void push(int item)
{
	if (top != 2047)
	{
		stack[++top] = item;
	}
	else
		return ;
}

int pop()
{
	if (top == -1)
	{
		return (0);
	}
	else
		return (stack[top--]);
}

int ft_space(char c)
{
   	return (c == ' ');
}
int is_operator(char c)
{
	return (c == '*' || c == '/' || c == '%' || c == '+' || c == '-');
}
int ft_num(char c)
{
	return (c >= '0' && c <= '9');
}
int do_op(int c, int d, char op)
{
	if (op == '*')
		return (c * d);
	else if (op == '/')
		 return (c / d);
	else if (op == '%')
		return (c % d);
	else if (op == '+')
		return (c + d);
	else if (op == '-')
		return (c - d);
	return (0);
}
int ft_rpn(char *str)
{
	int i = 0;
	int j = 0;
	while (*str)
	{
		if (ft_space(*str))
			;
		else if (!ft_space(*str) && ft_num(*str))
		{
			push(atoi(str));
			i++;
			while (ft_num(*str))
			{
				str++;
			}
		}
		else if (!ft_space(*str) && is_operator(*str))
		{
			j++;
			int op2 = pop();
			int op1 = pop();
			char op = *str;
			int result = do_op(op1, op2, op);
			push(result);
		}
		str++;
	}
	return (top == 0 && j - i = 1 && j != 0 && i != 0) ? 1 : 0;
}
int main (int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_rpn(av[1]))
			printf("%d\n", stack[top--]);
		else
			printf ("Error\n");
	}
	else
		printf("Error\n");
	return (0);
}
