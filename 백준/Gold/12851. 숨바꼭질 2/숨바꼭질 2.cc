#include <iostream>
#include<tuple>
#include<queue>
#include<string.h>

using namespace std;

int n, m;
int answer = 0x3f3f3f3f;
int cnt = 0;
int arr[100003];
int visit[100003] = { 0 };
bool first = true;


void bfs()
{
	queue<pair<int, int>> q;
	q.push({ n,0 });
	visit[n] = 1;

	while (!q.empty())
	{
		int cp = q.front().first;
		int cc = q.front().second;
		q.pop();

		visit[cp] = 1;
		if (!first && answer == cc && cp == m)
		{
			cnt++;
		}
		if (first && cp == m)
		{
			answer = cc;
			first = false;
			cnt++;
		}

		if (cp + 1 < 100001 && cp + 1 >= 0 && visit[cp + 1] != 1)
		{
			q.push({ cp + 1, cc + 1 });
		}
		if (cp - 1 < 100001 && cp - 1 >= 0 && visit[cp - 1] != 1)
		{
			q.push({ cp - 1, cc + 1 });
		}
		if (cp * 2 < 100001 && cp * 2 >= 0 && visit[cp * 2] != 1)
		{
			q.push({ cp * 2, cc + 1 });
		}
	}
}

int main()
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	bfs();

	cout << answer << '\n' << cnt;
}