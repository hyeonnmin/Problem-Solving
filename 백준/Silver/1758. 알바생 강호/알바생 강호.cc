#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> line;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;

		line.push_back(input);
	}

	sort(line.begin(), line.end(), greater<int>());

	long long total_tip = 0;
	for (int i = 0; i < N; ++i)
	{
		int tip = line[i] - i;
		total_tip += tip < 0 ? 0 : tip;
	}

	cout << total_tip;
}