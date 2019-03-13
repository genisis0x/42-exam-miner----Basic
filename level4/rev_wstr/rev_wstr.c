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

typedef struct node // struct Decelaration
{
	char		*word;
	struct node *next;
}				t_list;

t_list *head; // top of the list

t_list *ft_create(char *letter) // create a new node in the list
{
	t_list *new;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	new->word = letter;
	new->next = NULL;
	return (new);
}

void push(char *letter) //push the word in the list
{
	t_list *new = ft_create(letter);
	new->next = head;
	head= new;
}

static int ft_space(char c) // to check if it a space
{
	return (c == ' ' || c == '\t');
}

void ft_rev_wstr(char *str)
{
	int i = 0; // to iterate through each index of string
	int j; // to store every word
	int word_len = 0;
	int start; // to find the starting index of each word
	while (str[i])
	{
		j = 0;
		while (ft_space(str[i])) // till when there is a white space
			i++;
		start = i;
		word_len = 0;
		while (!ft_space(str[i]) && str[i]) // increase i till the string has not reached the end and it's not equal to space.
		{
			i++;
			word_len++; // count words
		}
		char *word = (char *)malloc(sizeof(char) * (word_len + 1)); // get space on heap for each word
		while (word_len) // copy each word to the space which is been get on the heap memory
		{
			word[j++] = str[start++];
			word_len--;
		}
		word[j] = '\0'; // assign end of each word
		push(word); // push the word in the list
		if (str[i]) // if the str[i] is not NULL then only increase and see the postion
			i++;
	}
}

void print_str(char *w) // function to print each word
{
	int i = 0;
	while (w[i])
	{
		write (1, &w[i], 1);
		i++;
	}
}

void print_rev(t_list *head) // print via recursion 
{
	if (head == NULL)
		return ;
	if (head)
	{
		print_str(head->word); // first print the word because the words are store in a reverse manner in the list
		if (head->next)// assign space till second last element because for last element we don't need space.
			write(1, " ", 1);
		print_rev(head->next); // call next head location and do the recursion.
	}
}

int main (int ac, char **av) // main driver function
{
	if (ac == 2)
	{
		ft_rev_wstr(av[1]); // to store each word in the stack implementation via list.
		print_rev(head); //print all words from the list.
	}
	write(1, "\n", 1);
	return 0;
}
