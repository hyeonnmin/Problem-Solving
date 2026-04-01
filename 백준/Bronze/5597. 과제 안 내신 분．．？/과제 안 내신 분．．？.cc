#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	vector<bool> check(31, false);

	for (int i = 0; i < 28; ++i)
	{
		int number;
		cin >> number;

		check[number] = true;
	}

	for (int i = 1; i < check.size(); ++i)
	{
		if (check[i] == false)
			cout << i << '\n';
	}
}