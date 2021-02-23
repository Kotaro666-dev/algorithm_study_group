#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const double EPS = 1e-10;

static int	binary_search(int age, int K)
{
	ll left = 0;
	ll right = pow(2, K);
	int counter = 0;

	if (right < age)
	{
		return (0);
	}
	while (left <= right)
	{
		counter++;
		ll middle = left + (right - left) / 2;
		if (middle == age)
		{
			break ;
		}
		else if (middle > age)
		{
			right = middle - 1;
		}
		else if (middle < age)
		{
			left = middle + 1;
		}
	}
	return (counter);
}

int			main(void)
{
	for (int age = 0; age < 100; age++)
	{
		for (int K = 0; K < 20; K++)
		{
			int counter = binary_search(age, K);
			if (counter == 0)
			{
				continue ;
			}
			if (K == counter)
			{
				printf("\x1b[32m");
				printf("[SUCCESS] ");
				printf("\x1b[39m");
				printf("age: %d, K: %d, counter: %d\n", age, K, counter);
			}
		}
	}
	return (0);
}