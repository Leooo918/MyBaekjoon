#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	priority_queue<int> pq;
	vector<pair<int, int>> v;
	vector<int> b;
	long long int total = 0;

	int N, K;
	int M, V, C;
	int index = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> M >> V;
		v.push_back({ M,V });
	}

	for (int i = 0; i < K; i++)
	{
		cin >> C;
		b.push_back(C);
	}

	sort(v.begin(), v.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < b.size(); i++)
	{
		int m = b[i];

		while (index < N && v[index].first <= m)
		{
			pq.push(v[index++].second);
		}

		if (!pq.empty())
		{
			total += pq.top();
			pq.pop();
		}
	}

	cout << total;
}