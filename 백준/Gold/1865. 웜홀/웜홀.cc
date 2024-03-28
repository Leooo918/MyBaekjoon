#include <iostream>
#include<map>
#include<vector>
#include<tuple>


using namespace std;


bool f(int N, vector<tuple<int, int, int>> v)
{
	vector<int> dist(N + 1, 0x3f3f3f3f);

	dist[1] = 0;

	int s, e, t;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			s = get<0>(v[j]);
			e = get<1>(v[j]);
			t = get<2>(v[j]);

			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}


	for (int j = 0; j < v.size(); j++) {
		s = get<0>(v[j]);
		e = get<1>(v[j]);
		t = get<2>(v[j]);
		if (dist[e] > dist[s] + t) {
			return true;
		}
	}

	return false;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int N, M, W;
		cin >> N >> M >> W;

		vector<tuple<int, int, int>> v;

		int s, e, t;
		for (int i = 0; i < M; i++)
		{
			cin >> s >> e >> t;
			v.push_back({ s,e,t });
			v.push_back({ e,s,t });
		}
		for (int i = 0; i < W; i++)
		{
			cin >> s >> e >> t;
			v.push_back({ s,e,-t });
		}

		if (f(N, v) == true)cout << "YES\n";
		else cout << "NO\n";
	}
}