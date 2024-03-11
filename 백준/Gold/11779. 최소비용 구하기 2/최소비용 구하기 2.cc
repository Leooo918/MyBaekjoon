#include <iostream>
#include<queue>
#include<vector>
#include<stack>
#include<string.h>

using namespace std;

int v, e;
int k, l;

vector<pair<int, int>> map[20001];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int arr[300001];
int res[300001];


int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ c,b });
	}

	cin >> k >> l;

	memset(arr, 30000, sizeof(arr));
	arr[k] = 0;

	pq.push({ 0,k });

	while (!pq.empty())
	{
		int cost = pq.top().first;		//현재 정점까지의 비용
		int vertex = pq.top().second;	//현재 정점
		pq.pop();

		if (arr[vertex] != cost) continue;

		for (int i = 0; i < map[vertex].size(); i++) {
			int nv = map[vertex][i].second;	//다음 정점
			int nc = map[vertex][i].first;	//다음 정점까지의 비용

			if (arr[vertex] + nc < arr[nv]) {
				arr[nv] = nc + arr[vertex];
				res[nv] = vertex;
				pq.push({ nc + arr[vertex] ,nv });
			}
		}
	}


	cout << arr[l] << '\n';

	int a = l;
	int cnt = 0;
	stack<int> s;

	while (a != 0) {
		s.push(a);
		a = res[a];
		cnt++;
	}

	cout << cnt << '\n';

	for(int i = 0; i < cnt; i++) {
		cout << s.top() << ' ';
		s.pop();
	}
}