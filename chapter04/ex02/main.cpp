#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

static int	tribonacci_sequence(int n, vector<ll> &memo, int &count)
{
	if (n <= 1)
	{
		return (0);
	}
	else if (n == 2)
	{
		return (1);
	}
	if (memo[n] != -1)
	{
		printf("memo[%d] = %d\n", n, memo[n]);
		return (memo[n]);
	}
	count++;
	return (memo[n] = tribonacci_sequence(n - 1, memo, count) + tribonacci_sequence(n - 2, memo, count) + tribonacci_sequence(n - 3, memo, count));
}

int main(void)
{
	vector<ll> memo(50, -1);
	int count = 0;

	printf("[n] : [res]\n");
	for (int i = 0; i < 30; i++)
	{
		ll res = tribonacci_sequence(i, memo, count);
		printf("[%d] : %lld\n", i, res);
	}
	printf("count = %d\n", count);
	return (0);
}