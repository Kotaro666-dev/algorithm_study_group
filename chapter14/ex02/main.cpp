#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;
const int NOT_VISITED = -1;

struct Edge {
    int to;
    ll weight;
    Edge(int to, ll weight) : to(to), weight(weight) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmax(T& a, T b)
{
    if (a <= 0 && b <= 0)
    {
        if (abs(a) < abs(b))
        {
            a = b;
            return true;
        }
    }
    else if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    // N = 頂点数、M = 辺の数
    int N, M;
    cin >> N >> M;

    Graph graph(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        ll weight;
        cin >> a >> b >> weight;
        graph[a].push_back(Edge(b, weight));
    }

    bool is_cycle = false; // 閉路があるかどうかのフラグ
    vector<ll> distance(N, NOT_VISITED);
    distance[0] = 0;
    for (int i = 0; i < N; i++)
    {
        bool has_updated = false;
        for (int v = 0; v < N; v++)
        {
            // まだ通っていない頂点からスタートだった場合は、スルーする
            if (distance[v] == NOT_VISITED)
            {
                continue;
            }

            for (auto edge: graph[v])
            {
                if (chmax(distance[edge.to], distance[v] + edge.weight))
                {
                    has_updated = true;
                }
            }
        }

        if (!has_updated)
        {
            break;
        }

        if (i == N - 1 && has_updated)
        {
            is_cycle = true;
        }
    }


    if (is_cycle)
    {
        cout << "inf" << endl;
    }
    else
    {
        ll answer = 0;
        for (int v = 0; v < N; v++)
        {
            if (abs(answer) < abs(distance[v]))
            {
                answer = distance[v];
            }
        }
        cout << answer << endl;
    }
    return (0);
}

/*
3 3
0 1 4
1 2 3
0 2 5
*/

/*
2 2
0 1 1
1 0 1
*/

/*
6 5
0 1 -1000000000
1 2 -1000000000
2 3 -1000000000
3 4 -1000000000
4 5 -1000000000
*/