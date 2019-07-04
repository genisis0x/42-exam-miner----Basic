/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 23:11:43 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/23 00:50:04 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*####################### PASSED IN EXAM ############################*/ 

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int no_words(char *s)
{
	int len = 0;

	while (*s)
	{
		if (ft_isspace(*s))
		{
			s++;
		}
		else
		{
			++len;
			while (*s && !ft_isspace(*s))
			{
				s++;
			}
		}
	}
	return (len);
}


char    **ft_split(char *str)
{
	char **res;
	int word_len = 0;
	int i = 0;
	int start;
	int k;
	int j = 0;
	int words = no_words(str);
	res = (char**)malloc(sizeof(char*) * (words + 1));
	while (str[i] && j < words)
	{
		while (str[i] && ft_isspace(str[i]))
		{
			i++;
		}
		start = i;
		while (str[i] && !ft_isspace(str[i]))
		{
			word_len++;
			i++;
		}
		res[j] = (char*)malloc(sizeof(char) * (word_len + 1));
		k = 0;
		while (word_len)
		{
			res[j][k] = str[start];
			word_len--;
			start++;
			k++;
		}
		res[j][k] = '\0';
		j++;
	}
	res[j] = 0;
	return (res);
}
/*int main (void)
{
	char** res;
	for (res = ft_split("asdf qwerty zxcv"); *res != '\0'; res++)
		printf("'%s',", *res);
	printf("\n");
	return (0);
}*/
