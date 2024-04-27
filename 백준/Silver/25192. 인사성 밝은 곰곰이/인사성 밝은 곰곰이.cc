#include<iostream>
#include<set>

using namespace std;

int t;
int cnt = 0;
set<string> v;
string input;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> input;

		if (input == "ENTER")
		{
			cnt += v.size();
			v.clear();
			continue;
		}
		v.insert(input);
	}
	cnt += v.size();

	cout << cnt;
}