#include <iostream>

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
		int N;
		cin >> N;

		int max_value = INT32_MIN;
		int min_value = INT32_MAX;

		for (int j = 0; j < N; ++j)
		{
			int input;
			cin >> input;

			max_value = max_value < input ? input : max_value;
			min_value = min_value > input ? input : min_value;
		}

		cout << min_value << " " << max_value << '\n';
	}
}