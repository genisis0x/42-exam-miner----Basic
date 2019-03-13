#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr;

	list_ptr = begin_list;
	if (list_ptr)
	{
		(*f)(list_ptr->data);
		ft_list_foreach(list_ptr->next, f);
	}
}
