#include <iostream>
#include <queue>
#include <algorithm>
#include<string.h>
#include <math.h>
#include <map>

using namespace std;

int n;
int arr[500000];
int compressed[500000];

int tree[500000 * 4 + 1];
long long sum = 0;


int SetValue(int start, int end, int node, int target)
{
	if (target < start) return tree[node];
	if (target > end) return 0;

	tree[node] += 1;
	if (start == end) return 0;

	int mid = (start + end) / 2;
	return SetValue(start, mid, node * 2, target) + SetValue(mid + 1, end, node * 2 + 1, target);
}

long long GetRight(int start, int end, int node, int target)
{
	if (target < start) return tree[node];
	if (target > end || start == end) return 0;

	int mid = (start + end) / 2;
	return GetRight(start, mid, node * 2, target) + GetRight(mid + 1, end, node * 2 + 1, target);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		compressed[i] = arr[i];
	}

	sort(compressed, compressed + n);

	map<int, int> compMap;
	for (int i = 0; i < n; i++)
	{
		compMap[compressed[i]] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int index = compMap[arr[i]];
		sum += SetValue(0, n - 1, 1, index);
	}

	cout << sum;
}