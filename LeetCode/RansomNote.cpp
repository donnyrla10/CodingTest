#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    bool answer = true;
    int alpha[26];
    for(int i=0; i<26; i++) alpha[i] = 0;
    
    for(int i=0; i<ransomNote.size(); i++) alpha[ransomNote[i]-'a']++;
    for(int i=0; i<magazine.size(); i++) alpha[magazine[i]-'a']--;
    
    for(int i=0; i<26; i++) if(alpha[i] > 0) return false;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << canConstruct("a", "b") << '\n';
    cout << canConstruct("aa", "ab") << '\n';
    cout << canConstruct("aa", "aab") << '\n';
    cout << canConstruct("aab", "baa") << '\n';
    return 0;
}
