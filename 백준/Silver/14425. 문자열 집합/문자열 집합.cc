#include<iostream>
#include<set>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	int cnt = 0;
	set<string> s;
	string input;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		s.insert(input);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> input;
		if (s.find(input) != s.end())
		{
			cnt++;
		}
	}

	cout << cnt;
}