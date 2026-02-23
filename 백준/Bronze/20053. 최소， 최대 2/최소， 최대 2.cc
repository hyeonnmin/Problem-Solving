#include <iostream>	

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;;

	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;

		int max = INT32_MIN;
		int min = INT32_MAX;
		for (int j = 0; j < N; ++j)
		{
			int input;
			cin >> input;
			if (input > max)
				max = input;
			if (input < min)
				min = input;
		}

		cout << min << " " << max << '\n';
	}
}