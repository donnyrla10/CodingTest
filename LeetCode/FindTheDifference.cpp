#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char findTheDifference(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for(int i=0; i<t.size(); i++) if(s[i] != t[i]) return t[i];
    return t[t.size()-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << findTheDifference("abcd", "abcde") << '\n';
    cout << findTheDifference("", "y") << '\n';
    return 0;
}
