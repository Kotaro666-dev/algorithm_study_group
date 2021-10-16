#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;
using Graph = vector<vector<int>>;

const int NOT_VISITED = -1;

bool bfs(const Graph &graph, vector<int> &distance, int vertex)
{
	distance[vertex] = 0;
	queue<int> queue;
	queue.push(vertex);

	while (!queue.empty())
	{
		int current_vertex = queue.front();
		queue.pop();
		for (auto next_vertex: graph[current_vertex])
		{
			if (distance[next_vertex] == NOT_VISITED)
			{
				distance[next_vertex] = distance[current_vertex] + 1;
				queue.push(next_vertex);
			}
			else
			{
				// もし現在の頂点と辺が繋がっている次の頂点の距離（色）が一緒だった場合の確認
				if (distance[current_vertex] == distance[next_vertex])
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	Graph graph(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> distance(N, NOT_VISITED);
	bool is_bipartite = true;
	for (int vertex = 0; vertex < N; vertex++)
	{
		if (distance[vertex] != NOT_VISITED)
		{
			continue;
		}
		is_bipartite = bfs(graph, distance, vertex);
		if (!is_bipartite)
		{
			break ;
		}
	}

	// デバッグ
	// for (int i = 0; i < N; i++)
	// {
	// 	cout << "distacne[" << i << "]: " << distance[i] << endl;
	// }

	if (is_bipartite)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return (0);
}

/*
テストケース

5 10
0 1
0 3
1 0
1 4
1 2
2 1
3 0
3 4
4 1
4 3

*/