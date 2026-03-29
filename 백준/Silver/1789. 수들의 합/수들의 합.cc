#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long S;
	cin >> S;

	long long N = sqrt(2 * S);

	while (N * (N + 1) > 2 * S)
		--N;

	cout << N;
}