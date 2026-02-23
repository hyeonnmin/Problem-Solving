#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int* arr = new int[n + 1];
	
	arr[0] = -1;
	arr[1] = -1;

	for (int i = 2; i <= n; ++i)
	{
		if (i == 2)
			arr[2] = 1;
		else if (i == 3)
			arr[3] = -1;
		else if (i == 4)
			arr[4] = 2;
		else if (i == 5)
			arr[5] = 1;
		else
		{
			int a = arr[i - 2];
			int b = arr[i - 5];

			if (a == -1 && b == -1)
				arr[i] = -1;
			else if (a == -1)
				arr[i] = b + 1;
			else if (b == -1)
				arr[i] = a + 1;
			else
				arr[i] = a < b ? (a + 1) : (b + 1);

		}

	}
	cout << arr[n];
}