#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

static void		print_out_array(vector<int> array, int N)
{
	printf("values in array: ");
	for (int i = 1; i <= N; i++)
	{
		printf("[%d]:%d ", i, array[i]);
	}
	printf("\n");
}

static int		count_occurrence_v(int N, int v)
{
	vector<int> a(N + 1);
	for (int i = 1; i <= N; i++)
	{
		if (i % 15 == 0)
		{
			a[i] = 15;
		}
		else if (i % 3 == 0)
		{
			a[i] = 3;
		}
		else if (i % 5 == 0)
		{
			a[i] = 5;
		}
		else
		{
			a[i] = i;
		}
	}
	print_out_array(a, N);
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == v)
		{
			counter++;
		}
	}
	return (counter);
}

int main(void)
{
	printf("[ANSWER]\n");
	printf("v = %d, answer = %d\n\n", 15, count_occurrence_v(100, 15));
	printf("[ANSWER]\n");
	printf("v = %d, answer = %d\n\n", 3, count_occurrence_v(100, 3));
	printf("[ANSWER]\n");
	printf("v = %d, answer = %d\n\n", 5, count_occurrence_v(100, 5));
	printf("[ANSWER]\n");
	printf("v = %d, answer = %d\n\n", -1, count_occurrence_v(100, -1));
	return (0);
}