#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	set<int> s1{ 0 };
	set<int> s2{ 1 };

	int n, m;
	cin >> n >> m;

	vector<vector<int>> group(n + 1);
	vector<int> set;

	for (int i = 0; i <= n; ++i)
	{
		group[i].push_back(i);
		set.push_back(i);
	}

	for (int i = 0; i < m; ++i)
	{
		int o, a, b;
		cin >> o >> a >> b;

		if (o == 0)
		{
			int g1 = group[set[a]].size() > group[set[b]].size() ? set[a] : set[b];
			int g2 = group[set[a]].size() > group[set[b]].size() ? set[b] : set[a];

			if (g1 != g2)
			{
				for (auto& e : group[g2])
				{
					group[g1].push_back(e);
					set[e] = g1;
				}
			}
		}
		else
		{
			if (set[a] == set[b])
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}