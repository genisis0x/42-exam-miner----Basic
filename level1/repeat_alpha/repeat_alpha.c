/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:46:50 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/06 18:46:54 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	int rep; // counter to count the alpha position in ascii table
	char c;
	if (ac == 2)
	{
		while (av[1][i])
		{
			c = av[1][i]; 
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) // if it's a alpha
			{
				if (c >= 'a' && c <= 'z')
					rep = c - 'a';
				if (c >= 'A' && c <= 'Z')
					rep = c - 'A';
				while (rep > 0) // when the counter is greater then 0 then write it
				{
					write (1, &c, 1);
					rep--;
				}
			}
			write (1, &c, 1); // anyways write each word for one time.
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
