#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int arr[3] = { 0,0,0 };
	pair<int, int> lt = { 0,0 };
	int tArr[3] = { 0,0,0 };
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t;
		string time;
		cin >> t >> time;
		int it = (stoi(time.substr(0, 2)) * 60) + stoi(time.substr(3, 5));

		arr[t]++;
		if (lt.first > 0)
		{
			tArr[lt.first] += it - lt.second;
		}
		if (arr[1] == arr[2]) lt = { 0,0 };
		else lt = { arr[1] > arr[2] ? 1 : 2, it };
	}

	tArr[lt.first] += (48 * 60) - lt.second;

	for (int i = 1; i < 3; i++)
	{
		int h = tArr[i] / 60;
		int m = tArr[i] % 60;

		if (h < 10) cout << "0";
		cout << h << ":";

		if (m < 10) cout << "0";
		cout << m << '\n';
	}
}