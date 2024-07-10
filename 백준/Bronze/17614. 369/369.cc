#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a;
	int cnt = 0;
	cin >> a;

	for (int i = 1; i <= a; i++)
	{
		string str = to_string(i);

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '3' || str[j] == '6' || str[j] == '9')
				cnt++;
		}
	}

	cout << cnt;
}