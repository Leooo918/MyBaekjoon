#include<iostream>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int f1, f2;

	int f[100]{ 0 };
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 2] + f[i - 1];
	}
	f1 = f[n];
	f2 = n - 2;

	cout << f1 << " " << f2;
}