#include <stdio.h>

int aranj(int n, int k)
{
	if (k > n)return 0;
	else
		if (k == 0)return 1;
		else
			return n * aranj(n - 1, k - 1);
}