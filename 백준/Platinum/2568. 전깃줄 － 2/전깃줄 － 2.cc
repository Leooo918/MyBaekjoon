#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> wires;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int a, b;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		wires.push_back({ a, b });
	}
	sort(wires.begin(), wires.end());	//sort by key

	vector<int> tail;	//contain value
	vector<int> pos(n);

	for (int i = 0; i < n; i++)
	{
		int value = wires[i].second;

		if (tail.empty() || tail.back() < value)
		{
			pos[i] = tail.size();
			tail.push_back(value);
		}
		else
		{
			auto it = lower_bound(tail.begin(), tail.end(), value);
			*it = value;
			pos[i] = it - tail.begin();
		}
	}


	cout << (n - tail.size()) << '\n';

	int length = tail.size() - 1;
	vector<int> result;
	for (auto a : wires) result.push_back(a.first);

	for (int i = n - 1; i >= 0; i--)
	{
		if (pos[i] == length)
		{
			result.erase(result.begin() + i);
			length--;
		}
	}

	for (int r : result) cout << r << '\n';
}                                                                                        