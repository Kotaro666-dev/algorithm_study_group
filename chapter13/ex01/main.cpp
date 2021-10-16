#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;
using Graph = vector<vector<int>>;

// 連結成分の個数（「任意の2頂点間にパスが存在するような部分グラフのうち極大なもの」）

void dfs(Graph &graph, vector<bool> &hasSeen, int vertex)
{
	hasSeen[vertex] = true;

	for (auto next_vertex: graph[vertex])
	{
		if (hasSeen[next_vertex])
		{
			continue;
		}
		dfs(graph, hasSeen, next_vertex);
	}
}

int main(void)
{
	int N, M; // 頂点数と辺数
	cin >> N >> M;

	Graph graph(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<bool> hasSeen(N, false);
	int number_of_subgraphs = 0;
	for (int vertex = 0; vertex < N; vertex++)
	{
		if (hasSeen[vertex])
		{
			continue;
		}
		dfs(graph, hasSeen, vertex);
		number_of_subgraphs++;
	}
	cout << number_of_subgraphs << endl;
	return (0);
}

// テストケース
/**
0 - 1
|   |
2 - 3

4 4
0 1
2 0
3 2
3 1
**/

/**
0 - 1 - 4
|
2 - 3   7

6 4
0 1
2 0
3 2
4 1
**/

/**
0   1 - 4
|
2 - 3   7

6 6
2 0
3 2
4 1
2 3
1 4
0 2
**/