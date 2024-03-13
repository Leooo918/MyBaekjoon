#include <iostream>
#include<queue>
#include<vector>
#include<stack>
#include<string.h>

using namespace std;

int n;
int cnt = 0;

int isused[40] = { 0 };		//행
int isused1[40] = { 0 };	//대각선/
int isused2[40] = { 0 };	//대각선\

void f(int c) {
	if (c == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isused[i] == 1 || isused1[i + c] == 1 || isused2[c - i + n - 1] == 1)
			continue;

		isused[i] = 1;
		isused1[i + c] = 1;
		isused2[c - i + n - 1] = 1;
		f(c + 1);
		isused[i] = 0;
		isused1[i + c] = 0;
		isused2[c - i + n - 1] = 0;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	f(0);
	cout << cnt << '\n';
}