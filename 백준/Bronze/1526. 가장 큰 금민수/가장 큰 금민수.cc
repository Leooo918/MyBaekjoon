#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = n; i > 3; i--)
	{
		bool isgms = true;
		int num = i;
		int j = 10;

		do
		{
			if (num % 10 != 7 && num % 10 != 4)
			{
				isgms = false;
				break;
			}
			num /= 10;
		} while (num > 0);

		if (isgms)
		{
			cout << i;
			break;
		}
	}
}