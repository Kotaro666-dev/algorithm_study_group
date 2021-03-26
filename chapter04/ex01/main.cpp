#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

static int	tribonacci_sequence(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	else if (n == 2)
	{
		return (1);
	}
	return (tribonacci_sequence(n - 1) + tribonacci_sequence(n - 2) + tribonacci_sequence(n - 3));
}


int main(void)
{
	printf("[n] : [res]\n");
	for (int i = 0; i <= 10; i++)
	{
		int res = tribonacci_sequence(i);
		printf("[%d] : %d\n", i, res);
	}
	return (0);
}