#include <iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<set>

using namespace std;


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	
	string input;
	set<string> s;

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		string temp;
		for (int j = i; j < input.size(); j++)
		{
			temp.push_back(input[j]);
			s.insert(temp);
		}
	}

	cout << s.size();
}