#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		sum += s[i] - '0';
	}

	cout << sum;
}