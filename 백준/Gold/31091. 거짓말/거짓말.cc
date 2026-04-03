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

	vector<int> note;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;

		note.push_back(input);
	}

	vector<int> diff(N + 2, 0);

	for (int i = 0; i < N; ++i)
	{
		if (note[i] <= 0)
		{
			int left = -note[i] + 1;
			int right = N + 1;

			diff[left]++;
			diff[right]--;
		}
		else
		{
			int left = 0;
			int right = note[i];
			diff[left]++;
			diff[right]--;
		}
	}

	vector<int> correct;
	int sum = 0;
	for (int i = 0; i < diff.size(); ++i)
	{
		sum += diff[i];
		if (i == sum)
			correct.push_back(i);
	}

	cout << correct.size() << '\n';
	for (auto& e : correct)
		cout << e << " ";
}
