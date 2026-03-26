#include <iostream>
#include <vector>	

using namespace std;

void record_coin(int cur, vector<int>& v)
{
	if (cur == 0)
		v[cur] = 0;
	else if (cur == 1)
		v[cur] = -1;
	else if (cur < 5)
	{
		if (v[cur - 2] != -1)
			v[cur] = v[cur - 2] + 1;
		else
			v[cur] = -1;
	}
	else
	{
		int two = v[cur - 2];
		int five = v[cur - 5];

		if (two != -1)
		{
			if (five != -1)
				v[cur] = two < five ? two + 1 : five + 1;
			else
				v[cur] = two + 1;
		}
		else
		{
			if (five != -1)
				v[cur] = five + 1;
			else
				v[cur] = -1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1, 0);

	for (int i = 0; i <= n; ++i)
	{
		record_coin(i, v);
	}
	cout << v[n];
}