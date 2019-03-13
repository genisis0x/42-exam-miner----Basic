/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:25:40 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/12 20:51:09 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct node
{
	char		*word;
	struct node *next;
}				t_list;

t_list *head;

t_list *ft_create(char *letter)
{
	t_list *new;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	new->word = letter;
	new->next = NULL;
	return (new);
}

void push(char *letter)
{
	t_list *new = ft_create(letter);
	new->next = head;
	head= new;
}

static int ft_space(char c)
{
	return (c == ' ' || c == '\t');
}

void ft_rev_wstr(char *str)
{
	int i = 0;
	int j;
	int word_len = 0;
	int start;
	while (str[i])
	{
		j = 0;
		while (ft_space(str[i]))
			i++;
		start = i;
		word_len = 0;
		while (!ft_space(str[i]) && str[i])
		{
			i++;
			word_len++;
		}
		char *word = (char *)malloc(sizeof(char) * (word_len + 1));
		while (word_len)
		{
			word[j++] = str[start++];
			word_len--;
		}
		word[j] = '\0';
		push(word);
		if (str[i])
			i++;
	}
}

void print_str(char *w)
{
	int i = 0;
	while (w[i])
	{
		write (1, &w[i], 1);
		i++;
	}
}

void print_rev(t_list *head)
{
	if (head == NULL)
		return ;
	if (head)
	{
		print_str(head->word);
		if (head->next)
			write(1, " ", 1);
		print_rev(head->next);
	}
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		ft_rev_wstr(av[1]);
		print_rev(head);
	}
	write(1, "\n", 1);
	return 0;
}
