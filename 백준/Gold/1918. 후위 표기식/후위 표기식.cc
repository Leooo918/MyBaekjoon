#include <iostream>
#include<stack>
#include<vector>
#include<tuple>


using namespace std;


int main(int argc, char** argv)
{
	ios::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	string input;
	stack<char> op;

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		char a = input[i];
		if (a >= 'A' && a <= 'Z')
			cout << a;
		else
		{
            if (a == '(')
                op.push(a);
            else if (a == '*' || a == '/')
            {
                while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(a);
            }
            else if (a == '+' || a == '-')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(a);
            }
            else if (a == ')')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
		}
	}

    while (!op.empty()) 
    {
        cout << op.top();
        op.pop();
    }
}