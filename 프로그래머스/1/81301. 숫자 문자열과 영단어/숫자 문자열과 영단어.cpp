#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string num = "";
	long long answer = 0;

	vector<string> nums{"zero", "one", "two", "three", "four", "five", "six", "seven","eight","nine"};

	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i]) == false) {
			for (int j = 0; j < nums.size(); j++) {
				if (s[i] == nums[j][0] && s[i + 1] == nums[j][1]) {
					num += j + '0';
					i += nums[j].size() - 1;
					break;
				}
			}

		}
		else {
			num += s[i];
		}
	}

	for (int i = 0; i < num.size(); i++) {
		if (num[i] == '0') {
			answer *= 1;
			continue;
		}
		long long n = 1;
		for (int j = 1; j < num.size() - i; j++) {
			n *= 10;
		}
		n *= num[i] - '0';

		answer += n;
	}
    
    return answer;
}