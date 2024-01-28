#include <iostream>
#include <cmath>
using namespace std;

string str;
char c;
int main(){
    int L;
    long long hash = 0;
    scanf("%d",&L);
    cin >> str;

    for(int i=0; i<str.size(); i++){
        c = str[i];
        hash += (c - 96) * pow(31, i);
    }

    printf("%lld\n", hash);

    return 0;
}