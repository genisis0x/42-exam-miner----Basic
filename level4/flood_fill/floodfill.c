/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:11:41 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/12 02:18:25 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"
void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c;
	c = tab[begin.y][begin.x];

	tab[begin.y][begin.x] = 'F';
	begin.y++;
	if (begin.y < size.y && tab[begin.y][begin.x] == c) // when the position + 1 in Y Direction is the given character
		flood_fill(tab, size, begin);
	begin.y--;
	begin.y--;
	if (begin.y >= 0 && tab[begin.y][begin.x] == c) // when the position - 1 in Y Direction is the given character
		flood_fill(tab, size, begin);
	begin.y++;
	begin.x++;
	if (begin.x < size.x && tab[begin.y][begin.x] == c) //when the position +1 in X Direction is the given character;
		flood_fill(tab, size, begin);
	begin.x--;
	begin.x--;
	if (begin.x >= 0 && tab[begin.y][begin.x] == c) // when the position - 1 in X Direction is the given character;
		flood_fill(tab, size, begin);
}
