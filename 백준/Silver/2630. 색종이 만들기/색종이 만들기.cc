#include <iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int n;
int w = 0, b = 0;
int a[129][129] = { 0 };

void p(int size, int x, int y, int c) {
	if (c == 4 || x >= n || y >= n) return;

	bool white = false;
	bool blue = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[x + j][y + i] == 1) blue = true;
			if (a[x + j][y + i] == 0) white = true;
			if (white == blue) break;
		}
		if (white == blue) break;	
	}

	if (white == blue) {
		p(size / 2, x, y, 0);
	}
	else {
		if (white)
			w++;
		else if (blue)
			b++;
	}
	if (c == 1)
	{
		x -= size;
		y += size;
	}
	else x += size;

	p(size, x, y, ++c);
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[j][i];
		}
	}

	p(n, 0, 0, 3);

	cout << w << "\n" << b << "\n";
 }