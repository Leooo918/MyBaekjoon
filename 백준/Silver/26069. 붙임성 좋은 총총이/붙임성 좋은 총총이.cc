#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int n;
set<string> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	string a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		if (a == "ChongChong")
			v.insert(b);
		else if (b == "ChongChong")
			v.insert(a);
		else if (find(v.begin(), v.end(), a) != v.end())
			v.insert(b);
		else if (find(v.begin(), v.end(), b) != v.end())
			v.insert(a);
	}

	cout << (v.size() + 1);
}