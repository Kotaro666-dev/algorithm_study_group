/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:52:30 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/30 21:14:52 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

bool func(int i, int w, const vector<int> &a, vector<vector<int>> &memo)
{
	// ベースケース
	if (i == 0) {
		if (w == 0)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}

	// memo の中身を確認
	if (memo[i][w] != -1)
	{
		return (true);
	}

	// a[i - 1]を選ばない場合
	if (func(i - 1, w, a, memo))
	{
		memo[i][w] = 1;
		return (true);
	}

	// a[i - 1]を選ぶ場合
	if (func(i - 1, w - a[i - 1], a, memo))
	{
		memo[i][w] = 1;
		return (true);
	}

	// どちらも false の場合は false
	memo[i][w] = -1;
	return false;
}

// 部分和の問題

int main(void)
{
	// N 個の整数、W の正の整数
	int N, W;
	cin >> N >> W;
	vector<int> a(N);
	vector<vector<int>> memo(N + 1, vector<int>(W + 1, -1));
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	if (func(N, W, a, memo))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return (0);
}