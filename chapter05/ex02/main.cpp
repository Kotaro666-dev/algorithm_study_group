/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:42:48 by kkamashi          #+#    #+#             */
/*   Updated: 2021/04/21 08:31:31 by kkamashi         ###   ########.fr       */
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

    vector<int>a(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    vector<int>b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
    }
    vector<int>c(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }

    int ans = 0;
    a[N] = INT_MAX;
    c[N] = INT_MAX;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.begin());

    // ソートされたbを固定して見ていく
    for (int i = 0; i < N; i++)
    {
        // b[i] 以上の値が現れる最初のイテレータ
        auto itr_a = lower_bound(a.begin(), a.end(), b[i]);
        // b[i] より大きい最初の値が現れる最初のイテレータ
        auto itr_c = upper_bound(c.begin(), c.end(), b[i]);

        int a_cases = itr_a - a.begin();
        int c_cases = c.size() - (itr_c - c.begin());
        ans += a_cases * c_cases;
    }
    cout << ans << endl;
    return (0);
}

// 例
// 6
// 3 14 159 2 6 53
// 58 9 79 323 84 6
// 2643 383 2 79 50 288
