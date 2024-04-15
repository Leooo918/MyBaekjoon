#include <iostream>
#include<tuple>
#include<queue>
#include<string.h>

using namespace std;

int n, m;
int arr[21][21];
int visit[26];
int answer = 0;

int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };

void dfs(int x, int y, int cnt)
{
	int a = arr[x][y];
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		visit[a] = 1;
		int nx = x + dx[i];
		int ny = y + dy[i];
		int na = arr[nx][ny];

		if (nx < 1 || nx > n || ny < 1 || ny > m || visit[na] == 1) continue;

		dfs(nx, ny, cnt);
		visit[a] = 0;
	}
	visit[a] = 0;

	answer = max(answer, cnt);
}

int main()
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			arr[i][j + 1] = input[j] - 'A';
		}
	}

	dfs(1, 1, 0);
	cout << answer;
}