/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:41:58 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/07 23:42:23 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#define STK_SIZE 2048 // max stack size 

int top = -1;
int stack[STK_SIZE]; 

void push(int item) // push function to implentation of stack
{
	if (top != 2047)
	{
		stack[++top] = item;
	}
	else
		return ;
}

int pop() // pop function to implentation of stack 
{
	if (top == -1)
	{
		return (0);
	}
	else
		return (stack[top--]);
}

int ft_atoi(char e) // atoi to convert to char to int
{
	return (e - '0');
}

int ft_space(char c) 
{
   	return (c == ' ');
}
int is_operator(char c) // check valid opertaor
{
	return (c == '*' || c == '/' || c == '%' || c == '+' || c == '-');
}
int ft_num(char c) // valid number between with 0 and 9 
{
	return (c >= '0' && c <= '9');
}
int do_op(char c, char d, char op) // operation function
{
	if (op == '*')
		return (ft_atoi(c) * ft_atoi(d));
	else if (op == '/')
		 return (ft_atoi(c) / ft_atoi(d));
	else if (op == '%')
		return (ft_atoi(c) % ft_atoi(d));
	else if (op == '+')
		return (ft_atoi(c) + ft_atoi(d));
	else if (op == '-')
		return (ft_atoi(c) - ft_atoi(d));
	return (0);
}
int ft_rpn(char *str) // main rpn cal function
{
	int i = 0;
	while (str[i])
	{
		if (ft_space(str[i]))
			;
		else if (!ft_space(str[i]) && ft_num(str[i]))
			push(ft_atoi(str[i]));
		else if (!ft_space(str[i]) && is_operator(str[i])) // operation for the single element 
		{
			int op2 = pop();
			int op1 = pop();
			int op = str[i];
			int result = do_op(op1, op2, op);
			push(result);
		}
		i++;
	}
	return (top == 0) ? 1 : 0;
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
