/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:12:38 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/12 01:47:21 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_list.h"
#include <stdlib.h>
void 	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *temp;
	t_list *traverse;

	if (*begin_list == NULL)
		return ;
	while(*begin_list && (!cmp((*begin_list)->data, data_ref)))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free (temp);
	}
	traverse = *begin_list;
	while (traverse && traverse->next)
	{
		if (!cmp(traverse->next->data, data_ref))
		{
			temp = traverse->next;
			traverse->next = temp->next;
			free(temp);
		}
		if (traverse->next->next)
			traverse = traverse->next;
		else
			break;
	}
	if (traverse->next && traverse->next->next ==  NULL)
	{
		if (!(cmp(traverse->next->data, data_ref)))
		{
			temp = traverse->next;
			traverse->next = NULL;
			free(temp);
		}
	}
}
