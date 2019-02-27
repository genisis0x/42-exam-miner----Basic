/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 00:01:55 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/27 00:02:18 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define abs(x) x < 0 ? -x : x

int is_correct(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'z'));
}

int		ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	unsigned int nb = 0;
	
	while (str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (is_correct(str[i]) && (str_base <= 16) && str[i] != 0)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			nb = nb *str_base + str[i] - '0';
		}
		if ((str[i] >= 'A' && str[i] <= 'F') && (abs(str_base) >= 11))
		{
			nb = nb *str_base + str[i] - 'A' + 10;
		}
		if ((str[i] >= 'a' && str[i] <= 'z') && (abs(str_base) >= 11))
		{
			nb = nb *str_base + str[i] - 'a' + 10;
		}
		i++;
	}
	return (nb * sign);
}

