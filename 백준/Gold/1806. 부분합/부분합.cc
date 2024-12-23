#include <iostream>
#include <queue>
#include<string.h>

using namespace std;

int n, s;
int arr[100001];

int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int length = 100001;
	int left = 0, right = 0;
    int sum = arr[0]; 

	while (right < n && left < n)
	{
		if (sum >= s)
		{
			length = min(length, (right - left + 1));
            sum -= arr[left];
			left++;
		}
		else
		{
			right++;
            sum += arr[right];
		}
	}

    if(length == 100001)
        cout << 0;
    else
	    cout << length;
}