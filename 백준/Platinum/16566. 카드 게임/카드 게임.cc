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

int parent[4000001];

int findValidIdx(int idx)
{
	if (idx == parent[idx])
		return idx;
	return parent[idx] = findValidIdx(parent[idx]);
}

void setValidIdx(int idx, int validIdx)
{
	idx = findValidIdx(idx);
	validIdx = findValidIdx(validIdx);

	if (idx != validIdx) 
		parent[idx] = validIdx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> cards(m);

	for (int i = 0; i < m; i++)
	{
		cin >> cards[i];
	}

	sort(cards.begin(), cards.end());
	for (int i = 0; i <= m; i++) parent[i] = i;	//initialize parent

	for (int i = 0; i < k; i++)
	{
		int target;
		cin >> target;

		int index = upper_bound(cards.begin(), cards.end(), target) - cards.begin();
		int validIdx = findValidIdx(index);

		cout << cards[validIdx] << '\n';
		setValidIdx(validIdx, validIdx + 1);
	}
}