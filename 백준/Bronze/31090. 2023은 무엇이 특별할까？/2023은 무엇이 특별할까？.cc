#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;

		int div = N % 100;

		if ((N + 1) % div == 0)
			cout << "Good\n";
		else
			cout << "Bye\n";
	}
}