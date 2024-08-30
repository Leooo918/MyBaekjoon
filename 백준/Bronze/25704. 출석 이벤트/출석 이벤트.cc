#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int n, cost;
	cin >> n >> cost;

	if (n < 5)
	{
		cost = cost;
	}
	else if (n < 10)
	{
		cost = cost - 500;
	}
	else if (n < 15)
	{
		cost = min(cost - 500, cost - (cost / 10));
	}
	else if (n < 20)
	{
		cost = min(cost - 2000, cost - (cost / 10));
	}
	else
	{
		cost = min(cost - 2000, cost - (cost / 4));
	}

	if (cost < 0)
	{
		cout << 0;
	}
	else
	{
		cout << cost;
	}
}
