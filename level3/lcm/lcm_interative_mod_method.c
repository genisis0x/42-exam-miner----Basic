#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

unsigned int gcd(unsigned int a, unsigned int b)
{
	int k = max(a,b);
	int m = min(a,b);
	// loop invariant: k ≥ m ∧ GCD(a,b) = GCD(k,m)
	while (m != 0)
	{
		int r = k % m;
		k = m;
		m = r;
	}
  // At this point, GCD(a,b) = GCD(k,m) = GCD(k,0) = k
  return k;
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int GCD = gcd(a, b);
	return GCD ? (a * b / GCD) : 0;
}

// TEST MAIN

// #include <stdio.h>
// #include <stdlib.h>
// int main(int ac, char **av)
// {
// 	if(ac >= 2)
// 	{
// 		printf("%d", lcm(atoi(av[1]), atoi(av[2])));
// }
// 	return 0;
// }
