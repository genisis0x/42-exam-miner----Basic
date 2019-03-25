/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 01:04:23 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/25 01:06:49 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ROT13_MODIFIER 13
/*
 * Rotate the given `str` inline.
 */

char *rot13(char *str) 
{
	for (int i = 0; '\0' != str[i]; i++) 
	{
		char c = *(str + i);
		if (('a' <= c && 'n' > c) || ('A' <= c && 'N' > c))
		{
			*(str + i) += ROT13_MODIFIER;
		} 
		else if (('n' <= c && 'z' >= c) || ('N' <= c && 'Z' >= c)) 
		{
			*(str + i) -= ROT13_MODIFIER;
		}
	}
	return str;
}
