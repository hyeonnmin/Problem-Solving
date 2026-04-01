#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string p1 = "AAAA";
	string p2 = "BB";
	string output;

	string input;
	cin >> input;
	input.push_back('.');

	int count = 0;
	for (auto& e : input)
	{
		if (e == 'X')
			++count;
		
		if (e == '.')
		{
			while (count != 0)
			{
				if (count >= 4)
				{
					count -= 4;
					output.append(p1);
				}
				else if (count >= 2)
				{
					count -= 2;
					output.append(p2);
				}
				else
				{
					cout << -1;
					return 0;
				}
			}
			output.push_back('.');
		}
	}
	output.pop_back();
	cout << output;
}