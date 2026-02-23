#include <iostream>

using namespace std;

bool checkLeft(char input)
{
	string left{ "qwertasdfgzxcv" };
	for (auto& c : left)
	{
		if (c == input)
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x[30];
	int y[30];
	string key[3]{ "qwertyuiop", "asdfghjkl", "zxcvbnm" };

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < key[i].size(); ++j)
		{
			int idx = key[i][j] - 'a';
			x[idx] = j;
			y[idx] = i;
		}
	}

	int time = 0;

	char curLeft, curRight;

	cin >> curLeft >> curRight;

	string input;
	cin >> input;

	for (auto& c : input)
	{
		int movingTime;
		if (checkLeft(c))
		{
			int curIdx = curLeft - 'a';
			int inputIdx = c - 'a';
			movingTime = abs(x[curIdx] - x[inputIdx]) + abs(y[curIdx] - y[inputIdx]);
			curLeft = c;
		}
		else
		{
			int curIdx = curRight - 'a';
			int inputIdx = c - 'a';
			movingTime = abs(x[curIdx] - x[inputIdx]) + abs(y[curIdx] - y[inputIdx]);
			curRight= c;
		}
		time += (movingTime + 1);
	}

	cout << time << '\n';
}