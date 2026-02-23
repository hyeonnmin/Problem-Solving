#include <iostream>	
#include <vector>

using namespace std;

int main()
{
	string board;
	cin >> board;

	string a{ "AAAA" };
	string b{ "BB" };

	string output;
	int count = 0;
	for (int i = 0; i < board.size(); ++i)
	{
		if (board[i] == 'X')
			++count;
		else
		{
			if (count % 2 == 0)
			{
				int count_a = count / 4;
				int count_b = (count % 4) / 2;
				for (int j = 0; j < count_a; ++j)
					output += a;
				for (int j = 0; j < count_b; ++j)
					output += b;
				output += '.';
				count = 0;
			}
			else
			{
				output = "-1";
				break;
			}
		}
	}
	if (count % 2 == 0)
	{
		int count_a = count / 4;
		int count_b = (count % 4) / 2;
		for (int j = 0; j < count_a; ++j)
			output += a;
		for (int j = 0; j < count_b; ++j)
			output += b;
	}
	else
		output = "-1";

	cout << output;
}