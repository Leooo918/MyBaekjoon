#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;



int main(int argc, char** argv)
{
	int a;
	cin >> a;
	vector<int> n(a);

	for (int i = 0; i < a; i++) {
		cin >> n[i];
	}


	sort(n.begin(), n.end());
	int answer = n[0] * n[a - 1];


	cout << answer;

}