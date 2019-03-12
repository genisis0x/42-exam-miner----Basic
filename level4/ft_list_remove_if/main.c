/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 23:56:41 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/12 01:46:36 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************** Test case for more infor use LLDB*********************/

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
t_list *head;

t_list *ft_create(int *item)
{
	t_list *res;
	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	res->data = item;
	res->next = NULL;
	return (res);
}

void push(int *item)
{
	t_list *node = ft_create(item);
	node->next = head;
	head = node;
}

int ft_compare(void *a, void *b)
{
	if (!(*(int *)(a) - *(int *)(b)))
		return (0);
	else
		return 1;
}

int main (void)
{
	int arr[9] = {1, 1, 2, 3, 5, 1, 7, 7, 8};
	push(&arr[5]);
	push(&arr[1]);
	push(&arr[2]);
	push(&arr[0]);
	push(&arr[6]);
	push(&arr[7]);
	push(&arr[0]);
	t_list *i = head;
	printf("The element in list are\n");
	while (i)
	{
		printf("%d", *(int *)i->data);
		i = i->next;
	}
	printf("\n");
	int (*cmp)() = &ft_compare;
	ft_list_remove_if(&head, &arr[0], cmp);
	printf("Elements left after removing %d are\n", arr[0]);
	while (head)
	{
		printf("%d", *(int *)head->data);
		head = head->next;
	}
	printf("\n");
	return 0;
}
