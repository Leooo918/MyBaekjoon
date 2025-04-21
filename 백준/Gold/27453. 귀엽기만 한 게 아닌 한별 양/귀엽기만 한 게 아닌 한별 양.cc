#include <iostream>
#include <queue>
#include <algorithm>
#include<string.h>

using namespace std;

//배열의 크기, 최대 불행 수
int n, m, k;

//맵
int arr[1001][1001];
//몇번째로 방문을 했는지
int visit[1001][1001][5][5];

//UP, DOWN, RIGHT, LEFT
int dx[5] = { 0,0,1,-1,0 };
int dy[5] = { 1,-1,0,0,0 };

struct node
{
	int x, y;
	int prevDir, pprevDir;
};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int ex, ey;
	int answer = -1;
	queue<node> q;
	cin >> n >> m >> k;

	memset(visit, -1, sizeof(visit));


	//입력 받는 부분
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = input[j] - '0';

			if (input[j] == 'S')
			{
				arr[i][j] = 0;
				q.push({ j,i,4,4 });
				visit[i][j][4][4] = 0;
			}

			if (input[j] == 'H')
			{
				arr[i][j] = 0;
				ex = j;
				ey = i;
			}

			if (input[j] == 'X') arr[i][j] = -1;
		}
	}

	while (!q.empty())
	{
		//x,y 현재 위치
		int x = q.front().x;
		int y = q.front().y;
		
		int prevDir = q.front().prevDir;
		int prevX = x - dx[prevDir], prevY = y - dy[prevDir];
		int prev = arr[prevY][prevX];

		int pprevDir = q.front().pprevDir;
		int pprevX = prevX - dx[pprevDir], pprevY = prevY - dy[pprevDir];
		int pprev = arr[pprevY][pprevX];
		
		int count = visit[y][x][prevDir][pprevDir];
		q.pop();

		//cout << prevDir << ' ' << pprevDir << ' ';
		//cout << x << ' ' << y << ' ' << count << '\n';

		//탐색 성공하면 탈출
		if (y == ey && x == ex)
		{
			answer = count;
			break;
		}

		//4방향 탐색
		for (int i = 0; i < 4; i++)
		{
			//다음 위치 후보
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == -1) continue;
			if (visit[ny][nx][i][prevDir] >= 0) continue;
			if (ny == prevY && nx == prevX) continue;

			//최근 3회 불행 총량, 최근 3회동안의 위치
			int misportune = arr[ny][nx] + arr[y][x] + prev;
			if (misportune > k) continue;

			q.push({ nx,ny, i, prevDir });
			visit[ny][nx][i][prevDir] = count + 1;
		}
	}

	cout << answer;
}