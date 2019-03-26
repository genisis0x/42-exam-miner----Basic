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

int top = -1; // top of the stack
int stack[STK_SIZE]; // stack decleration

void push(int item) // push function for stack implementation
{
	if (top != 2047) // Overflow condition
	{
		stack[++top] = item;
	}
	else
		return ;
}

int pop() // pop function for stack implementation
{
	if (top == -1) // Underflow Condition
	{
		return (0);
	}
	else
		return (stack[top--]);
}
/********Check Function Start************/

int ft_space(char c) // check space
{
   	return (c == ' ');
}
int is_operator(char c) // check Operator
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
/*********Check Function End***************/

int ft_rpn(char *str) // driver function
{
	int i = 0;
	int j = 0;
	while (*str)
	{
		if (ft_space(*str))
			;
		else if (!ft_space(*str) && ft_num(*str)) // when it's an operand push it into the stack.
		{
			push(atoi(str)); // it will hold the value of the number
			i++; // counter to see no of operand's
			while (ft_num(*str)) // when the number is greater then 9 skip it because atoi will take care of the number.
			{
				str++;
			}
		}
		else if (!ft_space(*str) && is_operator(*str)) // when its an operator pop out the two element which is in the order of operator 2nd and 1st.
		{
			j++; // counter to see no of operator's
			int op2 = pop();
			int op1 = pop();
			char op = *str;
			int result = do_op(op1, op2, op); // do_op for the given operator
			push(result); // push back the result
		}
		str++;
	}
	return (top == 0 && j - i = 1 && j != 0 && i != 0) ? 1 : 0; // check if the condition is reached the top and the spaces are fine or not if its correct RPN expression then only one element will be there in the stack which is final result.
}
int main (int ac, char **av) // main driver
{
	if (ac == 2)
	{
		if (ft_rpn(av[1]))
			printf("%d\n", stack[top--]); // if the condition is true and pop the element from the stack. 
		else
			printf ("Error\n");
	}
	else
		printf("Error\n");
	return (0);
}
