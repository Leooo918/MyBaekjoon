#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	vector<int> v(a);

	for (int i = 0; i < a; i++) cin >> v[i];

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	cout << v[b - 1];
}