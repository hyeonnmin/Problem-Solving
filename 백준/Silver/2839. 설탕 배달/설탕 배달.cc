#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	//int three_bag = 0;
	//int five_bag = 0;

	//
	//five_bag = N / 5;
	//int rest = N - 5 * five_bag;

	//while (rest % 3 != 0)
	//{
	//	if (rest == N)
	//	{
	//		cout << -1;
	//		return 0;
	//	}

	//	five_bag--;
	//	rest = N - 5 * five_bag;
	//}

	//three_bag = rest / 3;

	//cout << three_bag + five_bag;

	vector<int> record(N + 1, -1);
	record[0] = 0;

	for (int i = 3; i <= N; ++i)
	{
		if (i == 3)
			record[3] = 1;
		else if (i == 4)
			record[4] = -1;
		else
		{
			if (record[i - 5] != -1)
				record[i] = record[i - 5] + 1;
			else if (record[i - 3] != -1)
				record[i] = record[i - 3] + 1;
			else
				record[i] = -1;
		}
	}

	cout << record[N];

}