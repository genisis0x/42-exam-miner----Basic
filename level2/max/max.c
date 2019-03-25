/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:52:36 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/26 00:04:27 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		max(int* tab, unsigned int len)
{
	if (!tab)
	{
		return (0);
	}
	int cmp = tab[0];
	unsigned int i = 1;
	while (len > i)
	{
			if (tab[i] > cmp)
				cmp = tab[i];
		i++;
	}
	return (cmp);
}
