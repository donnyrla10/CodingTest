#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    int cnt[26];
    cin >> s;
    for(int i=0; i<26; i++) cnt[i] = 0; //초기화
    for(int i=0; i<s.size(); i++) cnt[s[i]-'a']++;
    for(int i=0; i<26; i++) cout << cnt[i] << ' ';
    cout << '\n';
    return 0;
}
