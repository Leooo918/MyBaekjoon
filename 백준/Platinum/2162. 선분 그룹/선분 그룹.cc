#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_map>
#include<unordered_set>

using namespace std;
using pos = pair<int, int>;
using line = pair<pos, pos>;

int ccw(pair<int, int>p1, pair<int, int>p2, pair<int, int>p3)
{
	int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool isIntersaction(line l1, line l2)
{
	pos p1 = l1.first;
	pos p2 = l1.second;
	pos p3 = l2.first;
	pos p4 = l2.second;

	int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0)
	{
		if (p1 > p2) swap(p2, p1);
		if (p3 > p4) swap(p3, p4);

		return p3 <= p2 && p1 <= p4;
	}

	return p1p2 <= 0 && p3p4 <= 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int group[3000];
	vector<line> lines;
	unordered_set<int> visited;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		lines.push_back({ {a, b}, {c, d} });
	}

	int groupCount = 0;
	int currentGroupSize = 0;
	int maxGroupSize = 0;
	queue<int> indexQ;

	for (int i = 0; i < lines.size(); i++)
	{
		if (visited.find(i) != visited.end()) continue;
		indexQ.push(i);
		visited.insert(i);

		groupCount++;
		currentGroupSize = 0;

		while (!indexQ.empty())
		{
			int index = indexQ.front();
			line l = lines[index];
			indexQ.pop();
			currentGroupSize++;

			for (int j = 0; j < lines.size(); j++)
			{
				if (visited.find(j) != visited.end()) continue;
				if (isIntersaction(l, lines[j]))
				{
					visited.insert(j);
					indexQ.push(j);
				}
			}
		}

		maxGroupSize = max(maxGroupSize, currentGroupSize);
	}

	cout << groupCount << '\n' << maxGroupSize;
}