#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<bool> record(N + 1, false);

	for (int i = 1; i <= N; ++i)
	{
		if (i == 1)
			record[i] = true;
		else if (i == 2)
			record[i] = false;
		else if (i == 3)
			record[i] = true;
		else
		{
			if (record[i - 1] == true)
				record[i] = false;
			else
				record[i] = true;
		}
	}

	if (record[N] == true)
		cout << "SK";
	else
		cout << "CY";
}