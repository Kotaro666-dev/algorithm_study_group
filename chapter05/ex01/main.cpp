/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:16:51 by kkamashi          #+#    #+#             */
/*   Updated: 2021/04/09 13:21:41 by kkamashi         ###   ########.fr       */
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
    sort(b.begin(), b.end());

    vector<int>ans(N);

    // a[i]を固定して、順番に見ていく
    // for loop分が O(N)、二分探索のlower_boundがO(log N) -> O(N long N)
    for (int i = 0; i < N; i++)
    {
        auto itr = lower_bound(b.begin(), b.end(), a[i]);
        ans[i] = itr - b.begin();
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", ans[i]);
    }
    return (0);
}