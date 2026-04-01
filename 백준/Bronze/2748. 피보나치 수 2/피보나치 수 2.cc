#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> record(n + 1);
	for (int i = 0; i < record.size(); ++i)
	{
		if (i == 0)
			record[0] = 0;
		else if (i == 1)
			record[1] = 1;
		else
		{
			record[i] = record[i - 1] + record[i - 2];
		}
	}

	cout << record[n];
}