#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;
using Graph = vector<vector<int>>;

const int VISITED = 0;
const int NOT_VISITED = -1;

// 幅優先探索
void bfs(const Graph &graph, vector<int> &distance, int vertex)
{
	distance[vertex] = VISITED;
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
		}
	}

}

int main(void)
{
	int N, M, s, t;
	cin >> N >> M >> s >> t;

	Graph graph(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	vector<int> distance(N, NOT_VISITED);
	// 頂点 s をスタートした探索
	bfs(graph, distance, s);

	// デバッグ用
	// for (int i = 0; i < N; i++)
	// {
	// 	cout << "distance[" << i << "]: " << distance[i] << endl;
	// }


	if (distance[t] != NOT_VISITED)
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

8 12 2 7
0 1
0 2
0 3
1 4
1 7
2 4
4 6
6 7
3 2
3 5
5 4
5 6

*/