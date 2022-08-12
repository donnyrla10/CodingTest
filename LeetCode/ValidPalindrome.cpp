#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    bool answer = true;
    string st;
    for(int i=0; i<s.size(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || isdigit(s[i]))   st += s[i];
        else if(s[i] >= 'A' && s[i] <= 'Z')                 st += s[i] + 32;
        
    }

    for(int i=0; i<st.size()/2; i++) if(st[i] != st[st.size()-1-i]) return false;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << isPalindrome("0P") << '\n';
    return 0;
}
