/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:16:51 by kkamashi          #+#    #+#             */
/*   Updated: 2021/04/21 07:52:39 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    vector<int>a(N);
    vector<int>b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    // 小さい順にソート
    // クイックソートの改良版イントロソートを使用
    // 最初はクイックソートを行い、再帰のレベルがソートされた要素数（の対数）を超えるとヒープソートに切り替える。
    // 計算量は、最悪の場合でも O(N log N)が保証されている
    sort(b.begin(), b.end());

    vector<int>ans(N);

    // a[i]を固定して、順番に見ていく
    // for loop分が O(N)、二分探索の lower_boundがO(log N) -> O(N log N)
    for (int i = 0; i < N; i++)
    {
        auto itr = lower_bound(b.begin(), b.end(), a[i]);
        ans[i] = itr - b.begin();
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d = %d\n", a[i], ans[i]);
    }
    return (0);
}