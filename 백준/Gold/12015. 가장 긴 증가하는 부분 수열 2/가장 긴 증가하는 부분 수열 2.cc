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
			continue;
		}

		auto it = lower_bound(tail.begin(), tail.end(), arr[i]);
		*it = arr[i];
	}

	cout << tail.size() << '\n';
}