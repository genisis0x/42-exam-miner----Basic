/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:05:17 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/24 19:05:20 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int		gcd;
	int		old_a;
	int		old_b;

	gcd = 0;
	old_a = a;
	old_b = b;
	while (1)
	{
		if (a == 0)
			break ;
		b %= a;
		if (b == 0)
			break ;
		a %= b;
	}
	gcd = (!b) ? a : b;
	return (gcd ? (old_a / gcd * old_b) : 0);
}
