#include <iostream>	
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<bool> cards(20000001, false);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;

		input += 10000000;
		cards[input] = true;
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int input;
		cin >> input;
		input += 10000000;
		if (cards[input] == true)
			cout << "1 ";
		else
			cout << "0 ";
	}
}