#include <iostream>
#include <queue>
#include<string.h>
using namespace std;

int n, m;
int arr[101][101];
int visit[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string l;
		cin >> l;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = l[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int dist = visit[cx][cy];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 0 || visit[nx][ny] > 0) continue;

			q.push({ nx,ny });
			visit[nx][ny] = dist + 1;
		}
	}
	
	cout << visit[n - 1][m - 1];
}