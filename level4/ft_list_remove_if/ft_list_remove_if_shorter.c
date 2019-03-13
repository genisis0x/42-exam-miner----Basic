/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 01:49:16 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/11 01:55:15 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void 	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*i;

	while (*begin_list && !cmp((*begin_list)->data, data_ref)) // if the match element is in the starting of the list then delete untill you got the element which doen't match.
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next) // if the match element is not in the starting but at any arbitary part of the list.
	{
		if (!cmp(i->next->data, data_ref)) // if it matches just delete the node and deleting the node means you are automatically getting shiftted by one.
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
		}
		else if (i->next) // if the element doen't matches then just move forward by one if the next value is not null. 
			i = i->next;
	}
}
