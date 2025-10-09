#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>

using namespace std;
#define INF 1e9
#define LL long long

int n, m;
int arr[1001][1001];
bool visit[1001][1001];
pair<int, int> connection[1001][1001];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1,-1, 0, 0 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = input[j] - '0';
		}
	}

	int index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 || visit[i][j]) continue;

			queue<pair<int, int>> q;
			vector<pair<int, int>> connected;
			q.push({ i, j });
			visit[i][j] = true;

			while (q.empty() == false)
			{
				int x = q.front().first;
				int y = q.front().second;

				q.pop();
				connected.push_back({ x, y });

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (arr[nx][ny] == 1 || visit[nx][ny]) continue;
					visit[nx][ny] = true;
					q.push({ nx, ny });
				}
			}

			for (pair<int, int> p : connected)
				connection[p.first][p.second] = { index, (int)connected.size() };
			index++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0) cout << 0;
			else
			{
				int ans = 1;
				set<int> visitidx;

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

					int idx = connection[nx][ny].first;
					int size = connection[nx][ny].second;
					if (size == 0) continue;	//이건 얘가 0이 아닌 경우임
					if (visitidx.find(idx) != visitidx.end()) continue;	//이미 방문했다면

					visitidx.insert(idx);
					ans += size;
				}
				cout << ans % 10;
			}
		}
		cout << '\n';
	}
}