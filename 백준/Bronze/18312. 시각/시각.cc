#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	int count = 0;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= 59; ++j)
		{
			for (int k = 0; k <= 59; ++k)
			{
				int hour0, hour1;
				int min0, min1;
				int sec0, sec1;

				hour0 = i / 10;
				hour1 = i % 10;
				min0 = j / 10;
				min1 = j % 10;
				sec0 = k / 10;
				sec1 = k % 10;

				vector<int> v;
				v.push_back(hour0);
				v.push_back(hour1);
				v.push_back(min0);
				v.push_back(min1);
				v.push_back(sec0);
				v.push_back(sec1);

				for (auto& e : v)
				{
					if (K == e)
					{
						++count;
						break;
					}
				}
			}
		}
	}

	cout << count;
}