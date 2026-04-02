#include <iostream>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int start_x, start_y;
	int end_x, end_y;

	cin >> N;
	cin >> start_x >> start_y;
	cin >> end_x >> end_y;

	int idx = 0;
	long long min_distance = LLONG_MAX;

	for (int i = 0; i < N; ++i)
	{
		int M;
		cin >> M;

		int pre_x = start_x;
		int pre_y = start_y;
		long long cur_distance = 0;

		for (int j = 0; j < M; ++j)
		{
			int mid_x, mid_y;
			cin >> mid_x >> mid_y;
			cur_distance += abs(mid_x - pre_x);
			cur_distance += abs(mid_y - pre_y);

			pre_x = mid_x;
			pre_y = mid_y;
		}
		cur_distance += abs(end_x - pre_x);
		cur_distance += abs(end_y - pre_y);

		if (min_distance > cur_distance)
		{
			min_distance = cur_distance;
			idx = i + 1;
		}
	}

	cout << idx;
}