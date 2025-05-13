#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

int arr[500001];
int tree[2000001];
int lazy[2000001];

void build(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build(start, mid, node * 2);
	build(mid + 1, end, node * 2 + 1);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void applylazy(int start, int end, int node)
{
	if (lazy[node] == 0) return;

	if ((end - start + 1) % 2 != 0)
	{
		tree[node] ^= lazy[node];
	}

	if (end != start)
	{
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}

	lazy[node] = 0;
}

long long query(int start, int end, int node, int left, int right)
{
	applylazy(start, end, node);
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) ^ query(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int left, int right, int value)
{
	applylazy(start, end, node);
	if (end < left || start > right) return;

	if (start >= left && end <= right)
	{
		lazy[node] ^= value;
		applylazy(start, end, node);

		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	int a, b, c, d;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	build(1, n, 1);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			update(1, n, 1, (b + 1), (c + 1), d);
		}
		else
		{
			cin >> b >> c;
			cout << query(1, n, 1, (b + 1), (c + 1)) << '\n';
		}
	}
}