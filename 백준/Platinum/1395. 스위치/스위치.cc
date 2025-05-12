#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

int tree[4000001];
bool lazy[4000001];

void applylazy(int start, int end, int node)
{
	if (lazy[node] == false) return;

	tree[node] = (end - start + 1) - tree[node];
	if (start != end)
	{
		lazy[node * 2] = !lazy[node * 2];
		lazy[node * 2 + 1] = !lazy[node * 2 + 1];
	}
	lazy[node] = 0;
}

long long query(int start, int end, int node, int left, int right)
{
	applylazy(start, end, node);
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void reverse(int start, int end, int node, int left, int right)
{
	applylazy(start, end, node);
	if (end < left || start > right) return;

	if (start >= left && end <= right)
	{
		tree[node] = (end - start + 1) - tree[node];

		if (start != end)
		{
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}

	int mid = (start + end) / 2;
	reverse(start, mid, node * 2, left, right);
	reverse(mid + 1, end, node * 2 + 1, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	int a, b, c;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		if (a == 0)
		{
			reverse(1, n, 1, b, c);
		}
		else
		{
			cout << query(1, n, 1, b, c) << '\n';
		}
	}
}