#include <stdlib.h>
int ft_intlen(unsigned int  n, int len)
{
	while(n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int				len;
	unsigned int	nb;
	char			*res;
	char			*str;

	str = "0123456789";
	len = nbr < 0 ? 1 : 0;
	nb = nbr < 0 ? -(unsigned int )nbr : nbr;
	len = ft_intlen(nb, len);
	len = (nbr == 0) ? 1 : len;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nbr == 0)
		res[0] = '0';
	res[len] = '\0';
	nb = nbr < 0 ? -(unsigned int)nbr : nbr;
	while (nb > 0)
	{
		res[--len] = str[nb % 10];
		nb /= 10;
	}
	if (nbr < 0)
		res[0] = '-';
	return (res);
}

/*#include <stdio.h>
int main (int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s", ft_itoa(atoi(av[1])));
	}
	printf("\n");
	return 0;
}*/
