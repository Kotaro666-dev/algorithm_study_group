/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:43:27 by kkamashi          #+#    #+#             */
/*   Updated: 2021/04/11 14:52:30 by kkamashi         ###   ########.fr       */
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
    int N, M;
    cin >> N >> M;

    vector<int>a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // 降順でソート
    sort(a.begin(), a.end(), greater<int>());

    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] > M)
        {
            continue ;
        }
        for (int j = 0; j < N; j++)
        {
            if (a[j] > M || a[i] + a[j] > M)
            {
                break ;
            }
            int remain = M - (a[i] + a[j]);
            if (remain == 1)
            {
                break ;
            }

        }

    }
    cout << ans << endl;
    return (0);
}