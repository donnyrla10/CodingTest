#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u'
       || c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U') return true;
    return false;
}

string reverseVowels(string s) {
    string answer = s;
    
    int l = 0, r = s.size()-1;
    while(l<r){
        if(isVowel(s[l]) && isVowel(s[r])){
            swap(s[l], s[r]);
            l++; r--;
        }
        else if(!isVowel(s[l]) && isVowel(s[r])) l++;
        else if(isVowel(s[l]) && !isVowel(s[r])) r--;
        else {
            l++; r--;
        }
    }
    answer = s;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << reverseVowels("hello") << '\n';
    cout << reverseVowels("leetcode") << '\n';
    return 0;
}
