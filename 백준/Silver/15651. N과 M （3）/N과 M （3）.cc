#include <iostream>
#include <vector>

using namespace std;

void BackTracking(int N, int M, vector<int>& v)
{
	if (v.size() == M)
	{
		for (auto& e : v)
			cout << e << " ";
		cout << '\n';

		return;
	}
	for (int i = 1; i <= N; ++i)
	{
		v.push_back(i);
		BackTracking(N, M, v);
		v.pop_back();
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> v;
	BackTracking(N, M, v);
}