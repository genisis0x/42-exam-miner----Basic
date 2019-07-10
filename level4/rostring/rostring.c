/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 01:46:39 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/23 01:46:41 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**************************** PASSES IN EXAM ***************************/

#include <unistd.h>

int main (int ac , char **av)
{
	int i = 0;
	int j;

	if (ac >= 2)
	{
		
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t')) // search for is_space and move the position.
			{
				i++;
			}
			j = i; // this is the postion of starting of the word.
			while (av[1][i])
			{
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t')) // find the next word.
				{
					i++;
				}
				while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t')) // find the next word.
				{
					i++;
				}
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t') && (av[1][i -1] == ' ' || av[1][i - 1] == '\t')) // print the word till it reaches last.
				{
					while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
					{
						write (1, &av[1][i], 1);
						i++;
					}
					write (1, " ", 1);
					i++;
				}
			}
			while (av[1][j] && (av[1][j] != ' ' && av[1][j] != '\t')) // print the first word now.
			{
				write (1, &av[1][j], 1);
				j++;
			}
	}
	write (1, "\n", 1);
}
