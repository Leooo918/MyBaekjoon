#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> sv(v);
	sort(sv.begin(), sv.end());
	sv.erase(unique(sv.begin(), sv.end()), sv.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(sv.begin(), sv.end(), v[i]) - sv.begin() << " ";
	}
}
