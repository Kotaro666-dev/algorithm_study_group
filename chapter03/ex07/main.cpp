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
	for (int bit = 0; bit < (1 << N - 1); bit++)
	{
		int temp = 0;
		for (int i = 0; i < N - 1; i++)
		{
			temp *= 10;
			temp += S[i] - '0'; // CHAR -> INT
			if (bit & (1 << i))
			{
				sum += temp;
				temp = 0;
			}
		}
		temp *= 10;
		temp += S.back() - '0'; // get the last word of S
		sum += temp;
	}
	printf("sum = %d\n", sum);
	return (0);
}