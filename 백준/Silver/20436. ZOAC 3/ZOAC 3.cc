#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> keys(26);
	vector<bool> pos(26, false);

	string r1 = "qwertyuiop";
	string r2 = "asdfghjkl";
	string r3 = "zxcvbnm";

	for (int i = 0; i < r1.size(); ++i)
	{
		int idx = r1[i] - 'a';
		keys[idx] = {0, i};
	}
	for (int i = 0; i < r2.size(); ++i)
	{
		int idx = r2[i] - 'a';
		keys[idx] = { 1, i };
	}
	for (int i = 0; i < r3.size(); ++i)
	{
		int idx = r3[i] - 'a';
		keys[idx] = { 2, i };
	}

	string left = "qwertasdfgzxcv";
	string right = "yuiophjklbnm";

	for (auto& e : left)
	{
		int idx = e - 'a';
		pos[idx] = true;
	}

	char point_left, point_right;
	cin >> point_left >> point_right;

	string input;
	cin >> input;

	int count = 0;

	for (auto& e : input)
	{
		int idx = e - 'a';

		if (pos[idx] == true)
		{
			pair<int, int> p1 = keys[idx];
			pair<int, int> p2 = keys[point_left - 'a'];

			count += abs(p1.first - p2.first) + abs(p1.second - p2.second) + 1;
			point_left = e;
		}
		else
		{
			pair<int, int> p1 = keys[idx];
			pair<int, int> p2 = keys[point_right - 'a'];

			count += abs(p1.first - p2.first) + abs(p1.second - p2.second) + 1;
			point_right = e;
		}

	}

	cout << count;
}