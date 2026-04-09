#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BackTracking(vector<int>& v, vector<bool>& visits, vector<int>& record, int M)
{

	if (record.size() == M)
	{
		for (auto& e : record)
			cout << e << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		if (visits[i] == false)
		{
			record.push_back(v[i]);
			visits[i] = true;

			BackTracking(v, visits, record, M);

			record.pop_back();
			visits[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> v;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	vector<int> record;
	vector<bool> visits(N, false);
	BackTracking(v, visits, record, M);
}