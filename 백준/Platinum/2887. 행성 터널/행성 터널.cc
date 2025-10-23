#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

struct satellite
{
	int id;
	int X, Y, Z;
};

struct edge
{
	int value;
	int to;

	edge(int t, int v) : to(t), value(v){}
};

struct comp
{
	bool operator()(const edge& A, const edge B)
	{
		return A.value > B.value;
	}
};
bool compareX(const satellite& a, const satellite& b) { return a.X < b.X; }
bool compareY(const satellite& a, const satellite& b) { return a.Y < b.Y; }
bool compareZ(const satellite& a, const satellite& b) { return a.Z < b.Z; }

priority_queue<edge, vector<edge>, comp> pq;
satellite arr[100001];
bool visit[100001];
//set<int> visit;
int tunel = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		arr[i].id = i;
		cin >> arr[i].X >> arr[i].Y >> arr[i].Z;
	}

	vector<vector<pair<int, int>>> adj(n);
	sort(arr, arr + n, compareX);
	for (int i = 0; i < n - 1; i++) {
		int u = arr[i].id;
		int v = arr[i + 1].id;
		int weight = abs(arr[i].X - arr[i + 1].X);
		adj[u].push_back({ v, weight });
		adj[v].push_back({ u, weight });
	}

	sort(arr, arr + n, compareY);
	for (int i = 0; i < n - 1; i++) {
		int u = arr[i].id;
		int v = arr[i + 1].id;
		int weight = abs(arr[i].Y - arr[i + 1].Y);
		adj[u].push_back({ v, weight });
		adj[v].push_back({ u, weight });
	}

	sort(arr, arr + n, compareZ);
	for (int i = 0; i < n - 1; i++) {
		int u = arr[i].id;
		int v = arr[i + 1].id;
		int weight = abs(arr[i].Z - arr[i + 1].Z);
		adj[u].push_back({ v, weight });
		adj[v].push_back({ u, weight });
	}

	int cnt = 0;
	pq.push(edge(0, 0));

	while (!pq.empty() && cnt < n)
	{
		edge cur = pq.top();
		pq.pop();

		if (visit[cur.to]) continue;
		visit[cur.to] = true;
		tunel += cur.value;
		cnt++;

		for (pair<int, int> v : adj[cur.to]) 
		{
			if (visit[v.first]) continue;
			pq.push(edge(v.first, v.second));
		}
	}

	cout << tunel;
}