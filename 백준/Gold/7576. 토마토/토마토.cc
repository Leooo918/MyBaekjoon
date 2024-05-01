#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int v[1001][1001];	//방문했는지 확인 겸 토마토 상태 + 숙성될 때 까지의 기간

//방향을 미리 정해두십시오
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n, m;
	int cnt = 0;
	queue<pair<int, int>> q;

	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[j][i];
			if (v[j][i] == 1)
				q.push({ j, i });	//bfs로 탐색 하기 때문에 어짜피 q에 넣을 건데 여기서 미리 넣은거
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
	    int y = q.front().second;
		q.pop();

		//현재 위치에서 4방향으로 이동하는데 가려고 하는 곳이 토마토상자를 벗어나지 않았고
		//숙성되지 않은 토마토라면 q에 넣어주십시오
		for (int i = 0; i < 4; i++)
		{
			 int nx = x + dx[i];
			 int ny = y + dy[i];

			if (nx >= n || nx < 0 || ny >= m || ny < 0 || v[nx][ny] != 0) continue;
            
            v[nx][ny] = v[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cnt = max(cnt, v[j][i] - 1);	//v배열에서 가장 큰 값을 빼오십시오
			if (v[j][i] == 0) {
				cout << -1;		//만약 숙성되지 않은 녀석이 있다면 -1로ㄱㄱ
				return 0;
			}
		}
	}

	cout << cnt;
}