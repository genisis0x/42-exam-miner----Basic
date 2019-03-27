/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpncalc.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:33:22 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/09 01:36:35 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*********************************Solution of RPN using the Operand stack implementation as a Link List*******************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int				data;
	struct	node			*next;
}					t_list;

t_list *head; // top of the stack which will be null in the starting.

t_list *ft_create(int item) // function will create the list and return the list by setting the value of list to the item.
{
	t_list *res = (t_list *)malloc(sizeof(t_list));
	res->data = item;
	res->next = NULL;
	return (res);
}

void push (int item) // push operation
{
	t_list *new;
	if (!(new = ft_create(item))) // overflow condition when heap is full
		return ;
	new->next = head;
	head = new;
}

int pop() // pop operation
{
	int item = 0;
	t_list *temp = ft_create(0);
	if (head == NULL) // stack is empty or underflow
	{
		return (0);
	}
	else
	{
		item = head->data; // store value of the item to written
		temp = head; // temp will be holding the value of head which is been pointed by
		head = head->next; // move the head by one position in the list
		free(temp); // free the list from the memory now
		return (item);
	}
}

/* checker functions start*/
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
int do_op(int c, int d, char op) // operation function
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

/* check function complete*/

int ft_rpn(char *str) // driver function
{
	int i = 0; // used to count total no of spaces.
	int j = 0; // used to count total no of operand and operator's.
	int flag = 1;
	while (ft_space(*str))
		str++;
	while (*str)
	{
		if (ft_space(*str) && !ft_space(*(str + 1)) && flag == 1 && *(str + 1) != 0)
			i++;
		else if (ft_space(*str))
		{
			if (flag == 1 && !ft_space(*(str + 1)) && *(str + 1) != 0)
			{
				i++;
				flag = 0;
			}
			;
		}
		else if (!ft_space(*str) && ft_num(*str)) // push when str is a operand
		{
			flag = 1;
			push(atoi(str));
			j++;
			while (ft_num(*str))
			{
				str++;
			}
			str--;  // trick
		}
		else if (!ft_space(*str) && is_operator(*str)) // pop and store the result in stack when the str is operator.
		{
			flag = 1;
			int op2 = pop();
			int op1 = pop();
			char op = *str;
			int result = do_op(op1, op2, op);
			push(result);
			j++;
		}
		str++;
	}
	return (head->next == NULL && (j - i) == 1 && j != 0 && i != 0) ? 1 : 0; // i & j are the values of spaces and operators and operand.
}

int main (int ac, char **av) // Main driver
{
	if (ac == 2)
	{
		if (ft_rpn(av[1]))
			printf("%d\n", pop());
		else
			printf ("Error\n");
	}
	else
		printf("Error\n");
	return (0);
}
