#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

static int count_action()
{
	int N;
	cin >> N;

	vector<int> array(N);
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
		if (array[i] % 2 != 0)
		{
			return (0);
		}
	}
	int counter = 1;
	while (true)
	{
		for (int i = 0; i < N; i++)
		{
			array[i] /= 2;
			if (array[i] % 2 != 0)
			{
				return (counter);
			}
		}
		counter++;
	}
}

int main(void)
{
	printf("answer = %d\n", count_action());
	return (0);
}