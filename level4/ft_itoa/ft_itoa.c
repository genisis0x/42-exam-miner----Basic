#include <stdlib.h>
int ft_intlen(unsigned int  n, int len) // int length
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
	int			len;
	unsigned int		nb;
	char			*res;
	char			*str;

	str = "0123456789"; // base str
	len = nbr < 0 ? 1 : 0; // increase len by one for -neg
	nb = nbr < 0 ? -(unsigned int )nbr : nbr; //convert to unsigned int for -neg
	len = ft_intlen(nb, len); // length of int
	len = (nbr == 0) ? 1 : len; // for 0 reset the len to 0 
	if (!(res = (char *)malloc(sizeof(char) * (len + 1)))) // initilize the dynamic memory
		return (NULL);
	if (nbr == 0)
		res[0] = '0';
	res[len] = '\0'; // null termination
	while (nb > 0) // assign all the values from back
	{
		res[--len] = str[nb % 10];
		nb /= 10;
	}
	if (nbr < 0) // if -neg assign '-' in starting
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
