#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n, answer = 0;
int arr[100002];
stack<int> tree;



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	tree.push(0);
	for (int i = 1; i <= n + 1; i++)
	{
		while (!tree.empty() && (arr[tree.top()] > arr[i]))
		{
			int check = tree.top();
			tree.pop();
			answer = max(answer, arr[check] * (i - tree.top() - 1));
		}
		tree.push(i);
	}
	cout << answer;
}