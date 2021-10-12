#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

int main(void)
{
	ll N, M;
	cin >> N >> M;

	vector<pair<ll, ll>> shops(N);
	for (ll i = 0; i < N; i++)
	{
		// first == ドリンクの値段、 second == 売っている最大本数
		cin >> shops[i].first >> shops[i].second;
	}
	sort(shops.begin(), shops.end());

	ll amount_paid = 0;
	ll i = 0;

	while (M != 0)
	{
		if (shops[i].second > M)
		{
			amount_paid += (shops[i].first * M);
			M = 0;
		}
		else
		{
			amount_paid += shops[i].first * shops[i].second;
			M -= shops[i].second;
		}
		i++;
	}
	cout << amount_paid << endl;
	return (0);
}