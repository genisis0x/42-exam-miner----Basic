unsigned int gcd(unsigned int a, unsigned int b)
{
	return b ? gcd(b, a % b) : a;
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int GCD = gcd(a, b);
	return GCD ? (a * b / GCD) : 0;
}

// TEST MAIN

/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if(ac >= 2)
	{
		printf("%d", lcm(atoi(av[1]), atoi(av[2])));
}
	return 0;
}
*/
