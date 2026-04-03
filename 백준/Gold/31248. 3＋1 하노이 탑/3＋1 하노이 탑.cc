#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<char> name;
vector<pair<char, char>> note;

void Hanoi(int N, int start, int mid, int end, vector<stack<int>>& v, int& count)
{
	if (N == 1)
	{
		int sub = v[start].top();
		v[start].pop();
		v[end].push(sub);
		++count;

		note.push_back({ name[start], name[end] });
	}
	else
	{
		Hanoi(N - 1, start, end, mid, v, count);

		int sub = v[start].top();
		v[start].pop();
		v[end].push(sub);
		++count;

		note.push_back({ name[start], name[end] });

		Hanoi(N - 1, mid, start, end, v, count);
	}
}

void FourHanoi(int N, int start, int mid1, int mid2, int end, vector<stack<int>>& v, int& count)
{
	if (N == 1)
	{
		int sub = v[start].top();
		v[start].pop();
		v[end].push(sub);
		++count;

		note.push_back({ name[start], name[end] });
	}
	else if (N == 2)
	{
		int sub = v[start].top();
		v[start].pop();
		v[mid1].push(sub);
		++count;

		note.push_back({ name[start], name[mid1] });

		sub = v[start].top();
		v[start].pop();
		v[end].push(sub);
		++count;

		note.push_back({ name[start], name[end] });

		sub = v[mid1].top();
		v[mid1].pop();
		v[end].push(sub);
		++count;

		note.push_back({ name[mid1], name[end] });
	}
	else
	{
		Hanoi(N - 2, start, mid1, mid2, v, count);
		FourHanoi(2, start, mid1, mid2, end, v, count);
		FourHanoi(N - 2, mid2, start, mid1, end, v, count);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<stack<int>> v(4);
	name.push_back('A');
	name.push_back('B');
	name.push_back('C');
	name.push_back('D');

	for (int i = N; i >= 1; --i)
	{
		v[0].push(i);
	}

	int count = 0;
	FourHanoi(N, 0, 1, 2, 3, v, count);

	cout << count << "\n";
	for (auto& e : note)
	{
		cout << e.first << " " << e.second << "\n";
	}
}