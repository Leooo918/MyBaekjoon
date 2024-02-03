#include<string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<iterator>
#include<map>

using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int time = 0;
	string s;
	vector<int> v = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		int t = s[i] - 'A';

		time += v[t];
	}

	cout << time;
}