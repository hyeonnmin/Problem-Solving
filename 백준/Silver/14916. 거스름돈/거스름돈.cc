#include <iostream>	

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int five = n / 5;
	if (five == 0)
	{
		if (n % 2 != 0)
			cout << -1;
		else
			cout << n / 2;
	}
	else
	{
		int count = INT32_MAX;
		for (int i = 0; i <= five; ++i)
		{
			int sub = n - i * 5;
			if (sub % 2 == 0)
			{	
				int cur = i + sub / 2;
				count = count > cur ? cur : count;
			}
		}
		if (count == INT32_MAX)
			cout << -1;
		else
			cout << count;
	}
}