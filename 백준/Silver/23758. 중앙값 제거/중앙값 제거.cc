#include<iostream>
#include<algorithm>
#include<tuple>

using namespace std;

int n;
int arr[2000001];

bool containZero()
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0) return true;
	}
	return false;
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    
	int cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int mid = (n + 1) / 2;

	for (int i = 0; i < mid; i++)
	{
		while (arr[i] > 1)
		{
			arr[i] = arr[i] / 2;
			cnt++;
		}
	}

	cout << (cnt + 1);
}