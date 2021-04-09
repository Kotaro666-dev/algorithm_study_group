/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:42:48 by kkamashi          #+#    #+#             */
/*   Updated: 2021/04/09 13:18:47 by kkamashi         ###   ########.fr       */
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
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    vector<int>b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
    }
    vector<int>c(N);
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }

    int ans = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.begin());

    // ソートされたbを固定して見ていく
    for (int i = 0; i < N; i++)
    {
        auto itr1 = lower_bound(a.begin(), a.end(), b[i]);
        auto itr2 = upper_bound(c.begin(), c.end(), b[i]);

        int a_cases = itr1 - a.begin();
        int c_cases = c.size() - (itr2 - c.begin());
        ans += a_cases * c_cases;
    }
    cout << ans << endl;
    return (0);
}