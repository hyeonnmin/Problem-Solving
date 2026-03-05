#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<char> operaters;
	stack<int> s;
	int count = 1;
	int max_num = 0;
	s.push(0);
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		if (s.top() == input)
		{
			s.pop();
			operaters.push_back('-');
		}
		else if (s.top() > input)
		{
			cout << "NO";
			return 0; 
		}
		else
		{
			while (!(count == input))
			{
				s.push(count);
				++count;
				operaters.push_back('+');
			}
			s.push(count);
			++count;
			operaters.push_back('+');

			s.pop();
			operaters.push_back('-');
		}
	}

	for (auto& e : operaters)
		cout << e << "\n";
}