#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int checkString(char a){
    switch (a){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

int romanToInt(string s){
    int answer = 0;
    for(int i=0; i<s.length(); i++){
        if(i != s.length()-1){
            if(s[i] == 'I' && s[i+1] == 'V') {
                answer += 4; i++;
            }
            else if(s[i] == 'I' && s[i+1] == 'X') {
                answer += 9; i++;
            }
            else if(s[i] == 'X' && s[i+1] == 'L') {
                answer += 40; i++;
            }
            else if(s[i] == 'X' && s[i+1] == 'C') {
                answer += 90; i++;
            }
            else if(s[i] == 'C' && s[i+1] == 'D') {
                answer += 400; i++;
            }
            else if(s[i] == 'C' && s[i+1] == 'M') {
                answer += 900; i++;
            }
            else answer += checkString(s[i]);
            continue;
        }
        answer += checkString(s[i]);
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << romanToInt("III") << '\n';
    cout << romanToInt("LVIII") << '\n';
    cout << romanToInt("MCMXCIV") << '\n';
}
