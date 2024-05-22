#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> A;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int b;
		cin >> b;


		int start = 0;
		int end = n - 1;
		int mid;

		bool isIt = false;
		while (end >= start)
		{
			mid = (start + end) / 2;
			if (A[mid] == b)
			{
				cout << 1 << "\n";
				isIt = true;
				break;
			}
			else if (A[mid] > b) end = mid - 1;
			else start = mid + 1;
		}
		if (isIt == false) {
			cout << 0 << "\n";
		}
	}
}