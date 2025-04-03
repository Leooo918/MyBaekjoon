#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int visit[10001];

void bfs(int before, int after) {
	queue<pair<int, string>> q;
	q.push({ before, "" });
	visit[before] = 1;

	while (!q.empty()) {
		int num = q.front().first;
		string op = q.front().second;
		q.pop();	

		if (num == after) {
			cout << op << "\n";
			return;
		}

		int dNum = (num * 2) % 10000;
		if (visit[dNum] != 1) {
			visit[dNum] = 1;
			q.push({ dNum, op + "D" });
		}

		int sNum = num - 1 < 0 ? 9999 : num - 1;
		if (visit[sNum] != 1) {
			q.push({ sNum, op + "S" });
			visit[sNum] = 1;
		}

		int lNum = (num % 1000) * 10 + (num / 1000);
		if (visit[lNum] != 1) {
			q.push({ lNum, op + "L" });
			visit[lNum] = 1;
		}

		int rNum = num / 10 + (num % 10) * 1000; 
		if (visit[rNum] != 1) {
			q.push({ rNum, op + "R" });
			visit[rNum] = 1;
		}
	}
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;

	int n, m;

	while (t--) {
		cin >> n >> m;
		memset(visit, 0, sizeof(visit));
		bfs(n, m);
	}
}
