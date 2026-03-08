#include <iostream>	
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	vector<string> poketmons;
	unordered_map<string, int> poketmons_map;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string input;
		cin >> input;
		poketmons.push_back(input);
		poketmons_map.insert({ input, i + 1 });
	}

	for (int i = 0; i < M; ++i)
	{
		string input;
		cin >> input;

		if (int('0') <= input[0] && input[0] <= int('9'))
		{
			int num;
			num = stoi(input);

			cout << poketmons[num - 1] << '\n';
		}
		else
		{
			cout << poketmons_map[input] << '\n';
			//for (int j = 0; j < poketmons.size(); ++j)
			//{
			//	if (poketmons[j] == input)
			//	{
			//		cout << j + 1 << '\n';
			//		break;
			//	}
			//}
		}

	}
}
