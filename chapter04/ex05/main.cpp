#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;
#define NOT_FOUND -1

static bool		is_num_753(int num)
{
	string str = to_string(num);
	// cout << str << endl;
	if (str.find('3') == NOT_FOUND || str.find('5') == NOT_FOUND || str.find('7') == NOT_FOUND)
	{
		return (false);
	}
	cout << str << endl;
	return (true);
}

static void		count_753(int K, int num, int &counter)
{
	// ベースケース
	if (num >= K)
	{
		return ;
	}
	// num が７５３数かどうかチェック
	if (is_num_753(num))
	{
		counter++;
	}
	// 3 を後ろに足すの場合
	count_753(K, (num * 10) + 3, counter);
	// 5 を後ろに足すの場合
	count_753(K, (num * 10) + 5, counter);
	// 7 を後ろに足すの場合
	count_753(K, (num * 10) + 7, counter);
}

int		main(void)
{
	int K = 5500;
	int num = 0;
	int counter = 0;
	count_753(K, num, counter);
	printf("counter = %d\n", counter);
	return (0);
}