#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;


int n, m;
vector <pair<int, int>> v;


bool IsFriend(int a, int b) {
	for (int i = 0; i < v.size(); i++) {
		if ((v[i].first == a && v[i].second == b)
			|| (v[i].first == b && v[i].second == a)) return true;
	}
	return false;
}

int FindFriend(int start, int end) {
	queue<pair<int, int>> q;
	vector<int> visit;
	q.push({ start, 0 });

	while (!q.empty()) {
		int a = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < m; i++) {
			if (find(visit.begin(), visit.end(), i) == visit.end()) {
				if (v[i].first == a) {
					if (v[i].second == end) return c + 1;
					q.push({ v[i].second, c + 1 });
					visit.push_back(i);
				}
				else if (v[i].second == a) {
					if (v[i].first == end) return c + 1;
					q.push({ v[i].first, c + 1 });
					visit.push_back(i);
				}
			}
		}
	}

	return 0;
}

int main(int argc, char** argv)
{
	cin >> n >> m;
	vector<int> f(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i] += FindFriend(i, j);
		}
	}


	cout << min_element(f.begin() + 1, f.end()) - f.begin();
}