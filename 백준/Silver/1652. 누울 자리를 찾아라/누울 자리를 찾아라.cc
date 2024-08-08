#include <iostream>

using namespace std;

int n, hCnt = 0, vCnt = 0;
int arr[101][101];
string s;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = s[j] == '.' ? 0 : 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int sitCnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && sitCnt++ == 1)
			{
				hCnt++;
			}
			else if(arr[i][j] == 1)
			{
				sitCnt = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int sitCnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] == 0 && sitCnt++ == 1)
			{
				vCnt++;
			}
			else if (arr[j][i] == 1)
			{
				sitCnt = 0;
			}
		}
	}

	cout << hCnt << " " << vCnt;
}