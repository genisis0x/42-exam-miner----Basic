unsigned int gcd(unsigned int a, unsigned int b) {
      unsigned int k = K;   // In order to state a simple, elegant loop invariant,
      unsigned int m = M;   // we keep the formal arguments constant and use local variables to do the calculations.
      // loop invariant: GCD(K,M) = GCD(k,m)
      while (k != m) {
         if (k > m) 
            { k = k-m; }
         else 
            { m = m-k; }
      }
      // At this point, GCD(K,M) = GCD(k,m) = GCD(k,k) = k
      return k;
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
