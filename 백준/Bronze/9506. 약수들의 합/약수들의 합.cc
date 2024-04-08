#include <iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	int input = 0;
	int sum = 0;
	vector<int> v;

	while (true)
	{
		sum = 0;
		v.clear();
		cin >> input;

		if (input == -1) break;

		for (int i = 1; i < input; i++)
		{
			if (input % i == 0) 
			{
				v.push_back(i);
				sum += i;
			}
		}

		if (sum == input)
		{
			cout << input << " = ";
			for (int i = 0; i < v.size() - 1; i++)
			{
				cout << v[i] << " + ";
			}
			cout << v[v.size() - 1] <<'\n';
		}
		else 
		{
			cout << input << " is NOT perfect.\n";
		}

	}
}