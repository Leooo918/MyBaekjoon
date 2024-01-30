#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int N, M, B;
	int T = 2147000000, H = INT16_MIN;
	cin >> N >> M >> B;
	vector<vector<int>> v(N);
	map<int, int> m;

	for (int i = 0; i < N; i++) {
		vector<int> vv(M);
		for (int j = 0; j < M; j++) {
			cin >> vv[j];
			m[vv[j]]++;
		}
		v[i] = vv;
	}


	for (int i = 0; i <= 256; i++) {
		int t = 0, h = i, b = B;

		for (auto iter : m) {
			if (iter.first > h) {
				b += iter.second * (iter.first - h);
				t += iter.second * (iter.first - h) * 2;
			}
			else if (iter.first < h) {
				b -= iter.second * (h - iter.first);
				t += iter.second * (h - iter.first);
			}
		}

		if (b >= 0)
		{
			if (t <= T || (T == t && H < h)) {
				T = t;
				H = h;
			}
		}

	}

	cout << T << " " << H;
}
