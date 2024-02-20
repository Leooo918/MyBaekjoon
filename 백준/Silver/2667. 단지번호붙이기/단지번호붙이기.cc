#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int t;
int a[26][26];
int visit[26][26];

int xx[4]{ 0,0,1,-1 };
int yy[4]{ 1,-1,0,0 };

int cnt = 0;
vector<int> v;
queue<pair<int, int>> q;

void bfs(int x, int y) {
	int item = 1;
	q.push({ x, y });
	cnt++;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int dx = cx + xx[i];
			int dy = cy + yy[i];


			if (dx >= 0 && dx < t && dy >= 0 && dy < t && a[dx][dy] != 0 && visit[dx][dy] != 1) {
				q.push({ dx,dy });
				visit[dx][dy] = 1;
				item++;
			}
		}
	}

	v.push_back(item);
}


int main(int argc, char** argv)
{
	cin >> t;

	cin.ignore();
	for (int i = 0; i < t; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < t; j++) {
			a[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			if (a[i][j] == 1 && visit[i][j] == 0) {
				visit[i][j] = 1;
				bfs(i, j);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << "\n";

	for (int i = 0; i < cnt; i++) {
		cout << v[i] << "\n";
	}
}