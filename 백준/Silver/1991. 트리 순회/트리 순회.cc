#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<tuple>

using namespace std;

int t;
pair<char, char> p[27];

void p1(char c) {
	if (c == '.')return;

	cout << c;
	p1(p[c - 'A'].first);
	p1(p[c - 'A'].second);
}

void p2(char c) {
	if (c == '.')return;

	p2(p[c - 'A'].first);
	cout << c;
	p2(p[c - 'A'].second);
}

void p3(char c) {
	if (c == '.')return;

	p3(p[c - 'A'].first);
	p3(p[c - 'A'].second);
	cout << c;
}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	char c[3];

	for (int i = 0; i < t; i++) {
		cin >> c[0] >> c[1] >> c[2];

		p[c[0] - 'A'].first = c[1];
		p[c[0] - 'A'].second = c[2];
	}

	p1('A');
	cout << '\n';
	p2('A');
	cout << '\n';
	p3('A');
}