#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int three_bag = 0;
	int five_bag = 0;

	
	five_bag = N / 5;
	int rest = N - 5 * five_bag;

	while (rest % 3 != 0)
	{
		if (rest == N)
		{
			cout << -1;
			return 0;
		}

		five_bag--;
		rest = N - 5 * five_bag;
	}

	three_bag = rest / 3;

	cout << three_bag + five_bag;

}