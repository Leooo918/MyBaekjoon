#include<iostream>

using namespace std;

int N, M, cnt = 0;
int arr[1000001];


int find(int num)
{
	if (arr[num] == num)
		return num;
	else
		return find(arr[num]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		arr[i] = i;

	int a, b;
	bool isComplete = false;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		if (isComplete == false)
		{
			a = find(a);
			b = find(b);

			if (a == b)
				isComplete = true;

			arr[b] = a;
			cnt++;
		}
	}

	if (isComplete == true)
		cout << cnt;
	else
		cout << 0;
}