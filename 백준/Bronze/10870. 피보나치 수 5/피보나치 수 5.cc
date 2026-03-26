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

	vector<int> v(n + 1, 0);

	for (int i = 0; i <= n; ++i)
	{
		if (i == 0)
			v[i] = 0;
		else if (i == 1)
			v[i] = 1;
		else
			v[i] = v[i - 1] + v[i - 2];
	}

	cout << v[n];
}