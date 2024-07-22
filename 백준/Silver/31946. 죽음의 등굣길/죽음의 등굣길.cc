#include<iostream>
#include<queue>

using namespace std;

int n, m, x, c;
int arr[101][101];
int visit[101][101];
bool isAlive;

int main()
{
	queue<pair<int, int>> q;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> x;

	c = arr[0][0];
	q.push({ 0,0 });
	visit[0][0] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cx == (n - 1) && cy == (m - 1))
		{
			cout << "ALIVE";
			return 0;
		}

		for (int i = - x; i <= x; i++)
		{
			for (int j = -(x - abs(i)); j <= x - abs(i); j++)
			{
				int nx = cx + i;
				int ny = cy + j;

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] == 1 || arr[nx][ny] != c) continue;

				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}

	cout << "DEAD";
}