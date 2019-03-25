/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:31:52 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/22 22:49:35 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

void ft_expand(char *s)
{
	int flag = 0;

	while (*s && ft_isspace(*s))
	{
		s++;
	}
	while (*s)
	{
		if (*s && (ft_isspace(*s)))
		{
			flag = 1;
		}
		if (*s && (!ft_isspace(*s)))
		{
			if (flag)
				write (1, "   ", 3);
			flag = 0;
			write (1, s, 1);
		}
		s++;
	}
}


int main (int ac, char **av)
{
	if (ac == 2)
		ft_expand(av[1]);
	write (1, "\n", 1);
	return (0);
}
