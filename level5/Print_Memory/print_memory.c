/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memorytest2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:38:22 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/25 23:14:05 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*####################### PASSED IN EXAM ############################*/ 

#include "unistd.h"

void ft_print_hex(int x) // Hexadecimal value of int 
{
	char *base = "0123456789abcdef";

	write(1, &base[x / 16], 1);
	write (1, &base[x % 16], 1);
}


void ft_putchar(char c) // Ascii value of int
{
	if (c >= 32 && c <= 126) // printable Ascii
		write(1, &c, 1);
	else
		write (1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i = 0; // counter for size
	size_t j; // counter for each 16 bytes

	unsigned char const *p = addr;

	while (i < size)
	{
		j = 0;
		while ( j < 16 && i + j < size) // to print each Byte at a time. 
		{
			ft_print_hex(*(p + i + j));
			if (j % 2)
				write (1, " ", 1);
			j++;
		}
		while ( j < 16) // to print the unitilized int's
		{
			write (1, "  ", 2);
			if (j % 2)
				write (1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size) // to print the Ascii values of the given it
		{
			ft_putchar(*(p + i + j));
			j++;
		}
		write (1, "\n", 1);
		i += 16;
	}
}


//#IMP Notes: 
//The main concept of print memory is to print each byte at a time because memory in real is always store in the cpu by the token of bytes. 
