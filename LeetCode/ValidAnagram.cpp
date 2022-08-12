#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    bool answer = true;
    int alphas[26];
    int alphat[26];
    for(int i=0; i<26; i++) {
        alphas[i] = 0;
        alphat[i] = 0;
    }
    for(int i=0; i<s.size(); i++) alphas[s[i]-'a']++;
    for(int i=0; i<t.size(); i++) alphat[t[i]-'a']++;
    
    for(int i=0; i<26; i++) if(alphat[i] != alphas[i]) return false;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << isAnagram("anagram", "nagaram") << '\n';
    cout << isAnagram("rat", "cat") << '\n';
    return 0;
}
