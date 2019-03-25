/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:01:24 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/24 19:01:32 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*trim_begin_end_space(char *str)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[j - 1] == ' ' || str[j - 1] == '\t')
		j--;
	s = (char*)malloc(sizeof(char) * (j - i + 1));
	if (s == NULL)
		return (NULL);
	while (k < j - i)
	{
		s[k] = str[i + k];
		k++;
	}
	s[k] = '\0';
	return (s);
}

void	epur_str(char *str)
{
	int		i;
	int		first;

	i = 0;
	first = 1;
	str = trim_begin_end_space(str);
	if (str != NULL)
	{
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				if (first == 1)
					write(1, &str[i], 1);
				first = 0;
			}
			else
			{
				first = 1;
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	free(str);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
