#include <iostream>
#include <vector>

using namespace std;

int R, C;

bool checkSea(vector<vector<bool>> land, int i, int j)
{
	if (i < 0 || j < 0 || i >= R || j >= C)
		return true;
	
	if (land[i][j] == false)
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	vector<vector<bool>> land(R, vector<bool>(C));
	vector<vector<bool>> newLand(R, vector<bool>(C));

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			char c;
			cin >> c;

			if (c == '.')
			{
				land[i][j] = false;
				newLand[i][j] = false;
			}
			else
			{
				land[i][j] = true;
				newLand[i][j] = true;
			}
		}
	}

	int startRow = R;
	int endRow = -1;
	int startCol = C;
	int endCol = -1;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (land[i][j] == true)
			{
				int count = 0;
				if (checkSea(land, i - 1, j))
					count++;
				if (checkSea(land, i + 1, j))
					count++;
				if (checkSea(land, i, j - 1))
					count++;
				if (checkSea(land, i, j + 1))
					count++;

				if (count >= 3)
					newLand[i][j] = false;
				else
				{
					if (startRow > i)
						startRow = i;
					if (startCol > j)
						startCol = j;
					if (endRow < i)
						endRow = i;
					if (endCol < j)
						endCol = j;
				}
			}
		}
	}
	for (int i = startRow; i <= endRow; ++i)
	{
		for (int j = startCol; j <= endCol; ++j)
		{
			if (newLand[i][j] == false)
				cout << ".";
			else
				cout << "X";
		}
		cout << '\n';
	}
}