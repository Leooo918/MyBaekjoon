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

	string input;
	for (int i = 0; i < 100; i++) {
		getline(cin, input);
		if (input == "")break;
		cout << input << "\n";
	}
}