#include<string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<iterator>
#include<cmath>

using namespace std;

int cnt = 0;
int r, c;

void p(int N, int x, int y) {
	if (x == c && y == r)
	{
		cout << cnt;
		return;
	}
	else if (c < x + N && r < y + N && c >= x && r >= y) {
		p(N / 2, x, y);
		p(N / 2, x + N / 2, y);
		p(N / 2, x, y + N / 2);
		p(N / 2, x + N / 2, y + N / 2);
	}
	else {
		cnt += N * N;
	}
}


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int N;
	cin >> N >> r >> c;

	p(pow(2, N), 0, 0);
}