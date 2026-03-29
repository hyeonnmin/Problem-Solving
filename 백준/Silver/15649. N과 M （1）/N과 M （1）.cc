#include <iostream>
#include <vector>

using namespace std;

void back_tracking(vector<bool>& visit, vector<int>& container, int size)
{
	if (container.size() == size)
	{
		for (auto& e : container)
			cout << e << " ";
		cout << '\n';

		return;
	}

	for (int i = 1; i < visit.size(); ++i)
	{
		if (visit[i] == false)
		{
			container.push_back(i);
			visit[i] = true;
			back_tracking(visit, container, size);

			container.pop_back();
			visit[i] = false;
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

	vector<bool> visit(N + 1, false);
	vector<int> container;

	back_tracking(visit, container, M);
}