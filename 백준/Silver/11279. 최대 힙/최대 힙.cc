#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n;
	cin >> n;
	priority_queue<int> pQ;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		
		if (a == 0) {
			if (pQ.size() == 0) cout << "0\n";
			else {
				cout << pQ.top() << "\n";
				pQ.pop();
			}
		}
		else {
			pQ.push(a);
		}
	}
}