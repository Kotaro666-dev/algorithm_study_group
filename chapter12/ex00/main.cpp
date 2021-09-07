#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

const int NOT_FOUND = -1;

static int find_target_index_in_sorted_array(vector<int> array, int target)
{
	sort(array.begin(), array.end());

	for (int i = 0; i < array.size(); i++)
	{
		if (target == array[i])
		{
			return (i);
		}
	}
	return (NOT_FOUND);
}


int main(void)
{
	cout << "場所を求めたい数は何ですか？" << endl;

	int target;
	cin >> target;

	vector<int> array = {4, 9, 7, 5, 1, 8, 6, 3, 0, 10, 2};
	int index = find_target_index_in_sorted_array(array, target);

	if (index == NOT_FOUND)
	{
		cout << target << "は、" << "配列に存在しない数字です。" << endl;
		return (0);
	}
	cout << target << "は、" << index + 1 << "番目に小さいです。" << endl;
	return (0);
}