#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int>v;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;

		v.push_back(input);
	}

	int black_num = 0;
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			for (int k = j + 1; k < N; ++k)
			{
				int sum = v[i] + v[j] + v[k];

				if (sum <= M)
				{
					if (sum > black_num)
						black_num = sum;
				}
			}
		}
	}
	cout << black_num;
}