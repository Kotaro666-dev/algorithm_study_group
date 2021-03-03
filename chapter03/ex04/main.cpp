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
	int maximum = INT_MIN;
	int minimum = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		maximum = max(maximum, array[i]);
		minimum = min(minimum, array[i]);
		printf("maximum = %d, minimum = %d\n", maximum, minimum);
	}
	int answer = maximum - minimum;
	printf("answer = %d\n", answer);
	return (0);
}