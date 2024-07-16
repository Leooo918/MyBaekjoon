#include<iostream>
#include<algorithm>
#include<tuple>

using namespace std;

int n, m;

int main()
{
	cin >> n >> m;

	if (n == 0 && m == 0)
	{
		cout << 0;
	}
	else if (n == 1 || n == -1 || m == 1 || m == -1)
	{
		cout << 1;
	}
	else
	{
		cout << 2;
	}
}