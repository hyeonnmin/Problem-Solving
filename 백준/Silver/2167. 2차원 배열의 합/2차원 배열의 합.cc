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

	int K;
	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		int r1, c1, r2, c2;
		int sum = 0;

		cin >> r1 >> c1 >> r2 >> c2;
		--r1;
		--c1;
		--r2;
		--c2;

		for (int r = r1; r <= r2; ++r)
		{
			for (int c = c1; c <= c2; ++c)
			{
				sum += matrix[r][c];
			}
		}

		cout << sum << '\n';
	}
}