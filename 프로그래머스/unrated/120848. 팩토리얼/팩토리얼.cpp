#include <string>
#include <vector>

using namespace std;

int fac(int n) {
	int r = 1;

	for (int i = 1; i <= n; i++) {
		r *= i;
	}

	return r;
}

int solution(int n) {
    int answer = 1;
    
    while (fac(answer) <= n) {
		answer++;
	}
    
    return answer - 1;
}

