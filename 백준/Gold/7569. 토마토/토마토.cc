#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int x, y, z;
int answer = 0;
int arr[101][101][101];

int xx[6]{ 1,-1,0,0,0,0 };
int yy[6]{ 0,0,1,-1,0,0 };
int zz[6]{ 0,0,0,0,1,-1 };


void bfs(queue<pair<int, pair<int, int>>> q) {
	int a = q.size();
	bool b = true;

	for (int j = 0; j < a; j++) {
		int cx = q.front().first;
		int cy = q.front().second.first;
		int cz = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int dx = cx + xx[i];
			int dy = cy + yy[i];
			int dz = cz + zz[i];

			if (dx < 0 || dx >= x || dy < 0 || dy >= y || dz < 0 || dz >= z) continue;

			if (arr[dx][dy][dz] == 0 ) {
				q.push({ dx, { dy,dz } });
				arr[dx][dy][dz] = 1;
				b = false;
			}
		}
	}

	if (b == false) answer++;
	if (q.size() > 0) bfs(q);
}

int main(int argc, char** argv)
{
	queue<pair<int, pair<int, int>>> q;
	cin >> x >> y >> z;

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				cin >> arr[k][j][i];
				if (arr[k][j][i] == 1) q.push({ k,{j,i} });
			}
		}
	}

	bfs(q);

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				if (arr[k][j][i] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << answer;
}
