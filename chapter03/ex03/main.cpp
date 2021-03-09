#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

int main(void)
{
	int N;
	cin >> N;

	vector<int> array(N);
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}
	int first_min = min(array[0], array[1]);
	int second_min = max(array[0], array[1]);
	for (int i = 2; i < N; i++)
	{
		if (array[i] < first_min)
		{
			second_min = first_min;
			first_min = array[i];
		}
		printf("first = %d, second = %d\n", first_min, second_min);
	}
	printf("answer = %d\n", second_min);
	return (0);
}