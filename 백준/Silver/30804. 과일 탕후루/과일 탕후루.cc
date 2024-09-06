#include <iostream>
#include<algorithm>
#include <queue>
#include<string>
#include<set>

using namespace std;

int n;
int arr[200001];
int num[10];

int l = 0;
int r = 0;
int answer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	while (l < n) {
		while (r < n) {
			num[arr[r++]]++;

			int cnt = 0;
			bool tang = false;
			for (int k = 1; k < 10; k++)
			{
				if (num[k] > 0) cnt++;
				if (cnt > 2)
				{
					tang = true;
					break;
				}
			}

			if (tang)
			{
				num[arr[--r]]--;
				break;
			}
		}

		answer = max(answer, r - l);
		num[arr[l++]]--;
	}

	cout << answer;
}
