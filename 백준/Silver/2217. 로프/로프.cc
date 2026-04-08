#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v; 
	for (int i = 0; i < N; ++i)
	{
		int weight;
		cin >> weight;
		v.push_back(weight);
	}

	sort(v.begin(), v.end(), greater<int>());

	int max_weight = 0;
	for (int i = 0; i < N; ++i)
	{
		int cur_weight = v[i] * (i + 1);
		if (max_weight < cur_weight)
			max_weight = cur_weight;

	}

	cout << max_weight;
}