#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;
#define INF 1e9
#define LL long long

int n;
int arr[1000001];
int idx[1000001];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	vector<int> tail;
	tail.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (tail.back() < arr[i])
		{
			tail.push_back(arr[i]);
			idx[i] = tail.size() - 1;
			continue;
		}

		auto it = lower_bound(tail.begin(), tail.end(), arr[i]);
		*it = arr[i];
		idx[i] = it - tail.begin();
	}

	cout << tail.size() << '\n';

	vector<int> result;
	int length = tail.size() - 1;

	for (int i = n - 1; i >= 0; i--)
	{
		if (idx[i] == length)
		{
			result.push_back(arr[i]);
			length--;
		}
	}

	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i] << ' ';
	}
}