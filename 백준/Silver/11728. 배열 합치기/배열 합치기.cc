#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> a;
	vector<int> b;

	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		a.push_back(input);
	}

	for (int i = 0; i < M; ++i)
	{
		int input;
		cin >> input;
		b.push_back(input);
	}

	vector<int> total;
	int point_a = 0;
	int point_b = 0;

	while (point_a < N && point_b < M)
	{
		if (a[point_a] < b[point_b])
		{
			total.push_back(a[point_a]);
			++point_a;
		}
		else
		{
			total.push_back(b[point_b]);
			++point_b;
		}
	}

	if (point_a < N)
	{
		while (point_a < N)
		{
			total.push_back(a[point_a]);
			++point_a;
		}
	}
	else
	{
		while (point_b < M)
		{
			total.push_back(b[point_b]);
			++point_b;
		}
	}

	for (auto& e : total)
		cout << e << ' ';
}