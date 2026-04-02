#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M, N;
	cin >> M >> N;

	vector<vector<bool>> matrix(M + 2, vector<bool>(N + 2, false));
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
			matrix[i][j] = true;
	}

	vector<pair<int, int>> direction;
	direction.push_back({ 0, 1 });
	direction.push_back({ 1, 0 });
	direction.push_back({ 0, -1 });
	direction.push_back({ -1, 0 });

	pair<int, int> cur{ 1, 1 };
	int count = 0;
	int direction_idx = 0;

	for(int i = 0; i < N * M - 1; ++i)
	{
		matrix[cur.first][cur.second] = false;
		pair<int, int> cur_direction = direction[direction_idx];

		while (matrix[cur.first + cur_direction.first][cur.second + cur_direction.second] != true)
		{
			direction_idx = (direction_idx + 1) % 4;
			++count;
			cur_direction = direction[direction_idx];
		}
		cur = { cur.first + cur_direction.first, cur.second + cur_direction.second };
	}

	cout << count;
}