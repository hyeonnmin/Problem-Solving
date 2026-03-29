#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pooling(vector<vector<int>> &matrix, int row, int col)
{
	int x1, x2, x3, x4;
	x1 = matrix[row][col];
	x2 = matrix[row][col + 1];
	x3 = matrix[row + 1][col];
	x4 = matrix[row + 1][col + 1];

	vector<int> pool;
	pool.push_back(x1);
	pool.push_back(x2);
	pool.push_back(x3);
	pool.push_back(x4);

	sort(pool.begin(), pool.end());

	return pool[2];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int input;
			cin >> input;

			matrix[i][j] = input;
		}
	}

	vector<vector<int>> result;
	while (N != 1)
	{
		N /= 2;
		result.resize(N, vector<int>(N));

		for (int i = 0; i < N * 2; i += 2)
		{
			for (int j = 0; j < N * 2; j += 2)
			{
				result[i / 2][j / 2] = pooling(matrix, i, j);
			}
		}

		matrix = result;
	}

	cout << result[0][0];
}