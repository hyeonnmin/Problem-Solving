#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int N, M;
		cin >> N >> M;

		
		vector<vector<int>> record(N, vector<int>(M, 0));

		for (int i = 0; i < M; ++i)
			record[0][i] = i + 1;

		for (int i = 1; i < N; ++i)
		{
			for (int j = 1; j < M; ++j)
			{
				record[i][j] = record[i][j - 1] + record[i - 1][j - 1];
			}
		}

		cout << record[N-1][M-1] << '\n';
	}
}