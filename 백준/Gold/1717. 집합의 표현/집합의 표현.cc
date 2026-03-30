#include <iostream>
#include <vector>

using namespace std;

int find(int a, vector<int>& v)
{
	if (v[a] == -1)
		return a;
	else
	{	
		v[a] = find(v[a], v);

		return find(v[a], v);
	}
}

void merge(int a, int b, vector<int>& v)
{
	int f1 = find(a, v);
	int f2 = find(b, v);

	if (f1 != f2)
		v[f1] = f2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1, -1);

	for (int i = 0; i < m; ++i)
	{
		int order;
		int a, b;
		cin >> order >> a >> b;

		if (order == 0)
			merge(a, b, v);
		else
		{
			if (find(a, v) == find(b, v))
				cout << "YES\n";
			else
				cout << "NO\n";
		}

	}
}