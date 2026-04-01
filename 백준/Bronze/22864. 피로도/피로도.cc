#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B, C, M;
	cin >> A >> B >> C >> M;

	int state = 0;
	int total_work = 0;

	for (int i = 0; i < 24; ++i)
	{
		if (state + A > M)
			state = (state - C < 0 ? 0 : state - C);
		else
		{
			state += A;
			total_work += B;
		}
	}

	cout << total_work;
}