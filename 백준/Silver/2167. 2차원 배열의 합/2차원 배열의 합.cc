#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> matrix(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int input;
			cin >> input;
			matrix[i][j] = input;
		}
	}

	vector<vector<int>> pre_sum(N + 1, vector<int>(M + 1, 0)); 
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int sum = 0;
			for (int r = 0; r <= i; ++r)
			{
				for (int c = 0; c <= j; ++c)
				{
					sum += matrix[r][c];
				}
			}
			pre_sum[i + 1][j + 1] = sum;
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		cout << pre_sum[r1 - 1][c1 - 1] + pre_sum[r2][c2] - pre_sum[r1 - 1][c2] - pre_sum[r2][c1 - 1] << '\n';
	}

}