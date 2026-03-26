#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	vector<vector<int>> v(N + 1);
	for (int i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
		{
			if (v[b].size() == 1)
				cout << "no\n";
			else
				cout << "yes\n";
		}
		else
		{
			cout << "yes\n";
		}
	}
}