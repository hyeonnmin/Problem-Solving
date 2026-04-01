#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int input;
	cin >> input;

	int output = 0;
	for (int i = 1; i < input; ++i)
	{
		int div = 100000;
		int sum = i;
		int sub = i;

		while (div != 0)
		{
			sum += (sub / div);
			sub %= div;
			div /= 10;
		}

		if (sum == input)
		{
			cout << i;
			return 0;
		}

	}
	cout << 0;
}