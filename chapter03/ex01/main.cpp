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
	for (int i = 0; i < N; i++)
	{
		printf("[%d]:%d ", i, array[i]);
	}
	printf("\n");
}

static int		find_maximum_id(int N, int v)
{
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = 10;
		}
		else
		{
			a[i] = 100;
		}
	}
	print_out_array(a, N);
	int found_id = -1;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == v)
		{
			found_id = i;
		}
	}
	return (found_id);
}


int main(void)
{
	printf("[ANSWER]\n");
	printf("v = %d, id = %d\n\n", 100, find_maximum_id(20, 100));
	printf("[ANSWER]\n");
	printf("v = %d, id = %d\n\n", 10, find_maximum_id(20, 10));
	return (0);
}