#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

tuple<int, int, int> change[11];
map<vector<int>, int> visit;

vector<int> swap(vector<int> arr, int a, int b)
{
	arr[a] ^= arr[b];
	arr[b] ^= arr[a];
	arr[a] ^= arr[b];
	return arr;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	vector<int> input;
	vector<int> sorted;

	cin >> n;
	input.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> input[i];
	sorted = input;
	sort(sorted.begin() + 1, sorted.end());

	cin >> m;
	for (int i = 0; i < m; ++i) cin >> get<0>(change[i]) >> get<1>(change[i]) >> get<2>(change[i]);

	priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;

	visit[input] = 0;
	q.push({ 0, input });


	while (!q.empty())
	{
		int cost = q.top().first;
		vector<int> cur = q.top().second;
		q.pop();

		if (cost > visit[cur]) continue;
		if (cur == sorted) break;

		for (int i = 0; i < m; ++i)
		{
			vector<int> nextvec = swap(cur, get<0>(change[i]), get<1>(change[i]));
			int nextcost = cost + get<2>(change[i]);

			auto it = visit.find(nextvec);
			if (it == visit.end() || nextcost < it->second)
			{
				visit[nextvec] = nextcost;
				q.push({ nextcost, nextvec });
			}
		}
	}


	if (visit.find(sorted) == visit.end()) cout << -1;
	else cout << visit[sorted];
}