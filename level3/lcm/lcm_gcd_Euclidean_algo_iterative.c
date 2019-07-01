unsigned int gcd(unsigned int a, unsigned int b) {
      unsigned int k = a;   // In order to state a simple, elegant loop invariant,
      unsigned int m = b;   // we keep the formal arguments constant and use local variables to do the calculations.
      // loop invariant: GCD(a,b) = GCD(k,m)
      while (k != m) {
         if (k > m)
            { k = k - m; }
         else
            { m = m - k; }
      }
      // At this point, GCD(a,b) = GCD(k,m) = GCD(k,k) = k
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
// link-> https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

// Algorithm
// GCD(a,b) = GCD(a - b, b) if-> (a>b)
// GCD(a,b) = GCD(a, b - a) if-> (b>a)
