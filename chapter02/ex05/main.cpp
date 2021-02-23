#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

static int binary_search(int age, int N)
{
	ll left = 0;
	ll right = N;
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
		for (int N = 0; N < 100; N++)
		{
			int counter = binary_search(age, N);
			if (counter == 0)
			{
				continue ;
			}
			int logN = round(log2(N));
			if (counter == logN)
			{
				printf("\x1b[32m");
				printf("[SUCCESS] ");
				printf("\x1b[39m");
				printf("age: %d, N: %d\n, logN: %d, counter: %d\n", age, N, logN, counter);
			}
		}
	}
}