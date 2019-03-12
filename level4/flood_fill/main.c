/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:52:35 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/12 02:22:04 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "t_point.h"
#include <stdio.h>
#include <stdlib.h>
char **make_area(char **zone, int _x, int _y)
{
	char **area;
	area = (char **)malloc(sizeof(char *) * _y);
	for (int i = 0; i < _y; ++i)
	{
		area[i] = (char *)malloc(sizeof(char) * _x);
		for (int j = 0; j < _x; ++j)
			area[i][j] = zone[i][2 * j];
	}
	return (area);
}
int main(void)
{
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 0 0 0 0 1",
		"1 1 0 0 0 0 0 0",
	};
	t_point size  = {8, 5};
	t_point begin = {0, 0};
	char **area = make_area(zone, size.x, size.y);
	flood_fill(area, size, begin);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", area[y][x]);
		}
		printf("\n");
	}
	free(area);
	return (0);
}
