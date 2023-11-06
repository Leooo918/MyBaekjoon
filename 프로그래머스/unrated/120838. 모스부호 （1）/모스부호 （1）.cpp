#include <string>
#include <vector>
#include<sstream>

using namespace std;

string solution(string letter) {
    string answer="";
    vector<string> mos = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    vector<string> moss = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    
    stringstream ss(letter);
    string temp;
    while(ss>>temp){
        for (int i = 0; i < mos.size(); i++) 
        {
         if(temp == mos[i]){
                answer += moss[i];
            }
        } 
    }
    
    
    return answer;
}