#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		string c;
		int num;
		cin >> c;

		if (c == "add") {
			cin >> num;
			if (find(v.begin(), v.end(), num) == v.end())		//존재하지 않으면 추가
				v.push_back(num);
		}
		else if (c == "remove") {
			cin >> num;
			if (find(v.begin(), v.end(), num) != v.end())		//존재하면 빼
				v.erase(find(v.begin(), v.end(), num));
		}
		else if (c == "check") {
			cin >> num;
			if (find(v.begin(), v.end(), num) != v.end())		//존재하면 1
				cout << 1 << "\n";
			else							//존재하지 않으면 0
				cout << 0 << "\n";
		}
		else if (c == "toggle") {
			cin >> num;
			if (find(v.begin(), v.end(), num) != v.end())		//존재하면 지우고
				v.erase(find(v.begin(), v.end(), num));
			else							//존재하지 않으면 추가
				v.push_back(num);
		}
		else if (c == "all") {
			v.clear();

			for (int j = 1; j < 21; j++)
				v.push_back(j);
		}
		else if (c == "empty") {
			v.clear();
		}
	}
}
