#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	string s;
	vector<int> v;
	stack<double> cal;

	cin >> s;
	
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '*')
		{
			double y = cal.top();
			cal.pop();
			double x = cal.top();
			cal.pop();
			cal.push(x * y);
		}
		else if (s[i] == '+')
		{
			double y = cal.top();
			cal.pop();
			double x = cal.top();
			cal.pop();
			cal.push(x + y);
		}
		else if (s[i] == '-')
		{
			double y = cal.top();
			cal.pop();
			double x = cal.top();
			cal.pop();
			cal.push(x - y);
		}
		else if (s[i] == '/')
		{
			double y = cal.top();
			cal.pop();
			double x = cal.top();
			cal.pop();
			cal.push(x / y);
		}
		else
		{
			double input = v[s[i] - 'A'];
			cal.push(input);
		}
	}
	cout << fixed << setprecision(2);
	cout << cal.top();


}