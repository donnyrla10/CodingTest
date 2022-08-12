#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int lengthOfLastWord(string s) {
    int answer = 0;
    for(int i=s.size()-1; i>=0; i--){
        if(answer == 0){
            if(s[i] == ' ') continue;
            else            answer++;
        }else{
            if(s[i] == ' ') break;
            else            answer++;
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << lengthOfLastWord("luffy is still joyboy") << '\n';
    return 0;
}
