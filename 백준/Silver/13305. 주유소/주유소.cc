#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int city[100001];
int road[100001];

int main()
{
	cin >> n;

	for (int i = 1; i < n; i++)
		cin >> road[i];

	for (int i = 1; i <= n; i++)
		cin >> city[i];

	long m = city[1];
	long cost = 0;

	for (int i = 1; i <= n - 1; i++) {
		if (city[i] < m) {
			m = city[i];
		}

		cost += m * road[i];
	}

	cout << cost;
}