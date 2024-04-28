#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
map<string, int> w;
vector<string> v;

bool cmp(string a, string b)
{
	if (a.size() == b.size() && w[a] == w[b])
		return a < b;

	if (w[a] == w[b])
		return a.size() > b.size();

	return w[a] > w[b];
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	string input;
	while (n--)
	{
		cin >> input;
		if (input.size() < m) continue;

		if (w.find(input) == w.end())
		{
			w[input] = 0;
			v.push_back(input);
		}

		w[input]++;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}