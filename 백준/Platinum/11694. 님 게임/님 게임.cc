#include <iostream>
#include <queue>
#include <algorithm>
#include<string.h>
#include <math.h>

using namespace std;

int n;
int flag = 0;
int input;
long long total = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		total ^= input;
		flag |= total > 1;
	}

	if (flag)
	{
		cout << (!total ? "cubelover" : "koosaga") << '\n';
	}
	else
	{
		cout << (total ? "cubelover" : "koosaga") << '\n';
	}

}