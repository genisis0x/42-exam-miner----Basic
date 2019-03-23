/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:28:43 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/14 17:43:55 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *head; // global variable to excess the list.

t_list *ft_create(int item) // function to create a new node in list
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	new->data = item;
	new->next = NULL;
	return (new);
}

static int  push(int item) // will push the item to the list
{
	t_list *new = ft_create(item);
	if (!new)
		return 0;
	new->next = head;
	head = new;
	return 1;
}


void ft_print(t_list *h) // Function to print the elements in the list.
{
	if (h == NULL)
		return ;
	else
	{
		printf("%d", h->data);
		ft_print(h->next);
	}
}
int main (void) // main driver
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
	push(arr[0]);
	push(arr[1]);
	push(arr[2]);
	push(arr[3]);
	push(arr[9]);

	int (*cmp)(int, int) = &ascending; // functional pointer which will compare the elements and return 1 or 0;
	sort_list(head, cmp); // sort list will sort the elements in ascending order.
	ft_print(head); // print all the elements in the list.
	return 0;
}
