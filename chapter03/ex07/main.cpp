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
	string S;
	cin >> S;

	int sum = 0;
	for (int bit = 0; bit < (1 << N); bit++)
	{
		for (int i = 0; i < N; i++)
		{
			if (bit & (1 << i))
			{
				printf("%d", S[i] - '0');
			}
		}
		printf("\n");
	}
	printf("sum = %d\n", sum);
	return (0);
}