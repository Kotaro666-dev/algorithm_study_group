#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

int main(void)
{
	int K, N;
	cin >> K >> N;

	int answer = 0;
	for (int X = 0; X <= K; X++)
	{
		for (int Y = 0; Y <= K; Y++)
		{
			int Z = N - (X + Y);
			if (0 <= Z && Z <= K)
			{
				answer++;
				printf("X = %d, Y = %d, Z = %d\n", X , Y, Z);
			}
		}
	}
	printf("answer = %d\n", answer);
	return (0);
}