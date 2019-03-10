/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:27:02 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/06 18:27:28 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_wdmatch(char *a, char *b)
{
	int j = 0;
	int i = 0;

	while ((a[i] && b[j]) != 0)
	{
		if (a[i] == b[j])
		{
			i++;
			j++;
			if (a[i] == '\0')
			{
				while (*a)
				{
					write (1, a, 1);
					a++;
				}
				return ;
			}
		}
		else
			j++;
	}
}

int main (int ac, char **av)
{
	if (ac == 3)
	{
		ft_wdmatch(av[1], av[2]);
	}
	write (1, "\n", 1);
	return (0);
}
