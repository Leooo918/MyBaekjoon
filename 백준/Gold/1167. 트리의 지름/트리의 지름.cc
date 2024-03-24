#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

map<int, vector<pair<int, int>>> node;
int visit[100002] = { 0, };
int answer = 0;
int ep = 0;


void dfs(int p, int s) {
	if (visit[p] == 1) return;

	visit[p] = 1;
	if (answer < s) {
		answer = s;
		ep = p;
	}

	for (int i = 0; i < node[p].size(); i++) {
		dfs(node[p][i].first, (s + node[p][i].second));
	}
}



int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (true) {
			cin >> b;
			if (b == -1) break;
			cin >> c;

			node[a].push_back({ b,c });
			node[b].push_back({ a,c });
		}
	}

	dfs(1, 0);

	answer = 0;
	memset(visit, 0, sizeof(visit));

	dfs(ep, 0);
	cout << answer;
}