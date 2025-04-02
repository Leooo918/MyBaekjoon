#include<iostream>
#include <algorithm>
#include<cmath>

using namespace std;

int n, m;
int arr1[201];
int arr2[201];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		for (int j = 0; j < m; j++) cin >> arr1[j];
		for (int j = 0; j < m; j++) cin >> arr2[j];

		int left = 0;
		for (int j = 0; j < m; j += 2)
		{
			if (arr1[j] < arr2[j])
			{
				left++;
			}
		}
		cout << left << '\n';
	}
}
