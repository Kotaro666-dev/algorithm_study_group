#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;
using Graph = vector<vector<int>>;

const int NOT_VISITED = -1;

/* 4 方向への隣接座標への移動を表すベクトル */
// 右、上、左、下
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

// 参考書：https://qiita.com/drken/items/0c7bab0384438f285f93

int main(void)
{
	int W, H;
	cin >> W >> H;

	vector<string> map(H);
	for (int i = 0; i < H; i++)
	{
		cin >> map[i];
	}

	// スタート地点とゴール地点の座標を取得
	int start_x, start_y, goal_x, goal_y;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] == 'S')
			{
				start_x = i;
				start_y = j;
			}
			else if (map[i][j] == 'G')
			{
				goal_x = i;
				goal_y = j;
			}
		}
	}
	// printf("start_x = %d, start_y = %d\n", start_x, start_y);
	// printf("goal_x = %d, goal_y = %d\n", goal_x, goal_y);


	vector<vector<int>> distance(H, vector<int>(W, NOT_VISITED));
	// スタート地点を 0 にする
	distance[start_x][start_y] = 0;

	// 探索中に各マスはどのマスから来たのかを表す配列
	vector<vector<int>> previous_x(H, vector<int>(W, NOT_VISITED));
	vector<vector<int>> previous_y(H, vector<int>(W, NOT_VISITED));

	// 「一度見た頂点」のうち「まだ訪れていない頂点」を表すキュー
	queue<pair<int, int> > queue;
	queue.push(make_pair(start_x, start_y)); // スタート地点を push

	// 幅優先探索
	while (!queue.empty())
	{
		pair<int, int> current_position = queue.front();
		int x = current_position.first;
		int y = current_position.second;
		queue.pop();

		//　隣接している座標を確認
		for (int direction = 0; direction < 4; direction++)
		{
			int next_position_x = x + dx[direction];
			int next_position_y = y + dy[direction];

			int is_outside_of_map = next_position_x < 0 || next_position_x >= H || next_position_y < 0 || next_position_y >= W;
			if (is_outside_of_map)
			{
				continue;
			}
			if (map[next_position_x][next_position_y] == '#')
			{
				continue;
			}

			// まだ訪問していない座標だった場合
			if (distance[next_position_x][next_position_y] == NOT_VISITED)
			{
				queue.push(make_pair(next_position_x, next_position_y));
				distance[next_position_x][next_position_y] = distance[x][y] + 1;
				previous_x[next_position_x][next_position_y] = x;
				previous_y[next_position_x][next_position_y] = y;
			}
		}

	}


	// 結果を出力
	printf("最短経路の手数表示\n");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] != '.' && map[i][j] != 'G')
			{
				cout << setw(3) << map[i][j];
			}
			else
			{
				cout << setw(3) << distance[i][j];
			}
		}
		cout << endl;
	}

	// スタート地点からゴール地点までの最短経路マップを出力
	int x = goal_x;
	int y = goal_y;
	while (x != NOT_VISITED && y != NOT_VISITED)
	{
		map[x][y] = 'X';

		int next_x = previous_x[x][y];
		int next_y = previous_y[x][y];

		x = next_x;
		y = next_y;
	}
	printf("最短経路マップ\n");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] == 'X')
			{
				printf("\033[31m");
				cout << setw(3) << map[i][j];
				printf("\033[0m");
			}
			else
			{
				cout << setw(3) << map[i][j];
			}
		}
		cout << endl;
	}
	return (0);
}

/*

テストケース

8 8
.#....#G
.#.#....
...#.##.
#.##...#
...###.#
.#.....#
...#.#..
S.......

*/