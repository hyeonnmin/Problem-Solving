#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R, C;
	cin >> R >> C;

	vector<vector<char>> m(R + 2, vector<char>(C + 2, '.'));
	vector<vector<char>> after_m(R + 2, vector<char>(C + 2, '.'));

	for (int i = 1; i <= R; ++i)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= C; ++j)
		{
			m[i][j] = input[j - 1];
			after_m[i][j] = input[j - 1];
		}
	}

	int min_row = 11, min_col = 11;
	int max_row = -1, max_col = -1;

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (m[i][j] == 'X')
			{
				int count = 0;
				
				count += (m[i - 1][j] == '.' ? 1 : 0);
				count += (m[i][j - 1] == '.' ? 1 : 0);
				count += (m[i + 1][j] == '.' ? 1 : 0);
				count += (m[i][j + 1] == '.' ? 1 : 0);

				if (count >= 3)
					after_m[i][j] = '.';
				else
				{
					min_row = min_row > i ? i : min_row;
					min_col = min_col > j ? j : min_col;
					max_row = max_row > i ? max_row : i;
					max_col = max_col > j ? max_col : j;
				}
			}
		}
	}

	for (int i = min_row; i <= max_row; ++i)
	{
		for (int j = min_col; j <= max_col; ++j)
			cout << after_m[i][j];
		cout << '\n';
	}
}