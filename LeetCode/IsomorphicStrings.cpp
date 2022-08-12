#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t) {
    bool answer = false;
    string s1 = "0", t1 = "0";
    int index = 1;
    for(int i=1; i<s.size(); i++){
        char c = s[i];
        int flag = -1;
        for(int j=0; j<i; j++){
            if(c == s[j]) {
                flag = j;
                break;
            }
        }
        if(flag != -1) s1 += (to_string(flag)+to_string(flag));
        else           s1 += to_string(index++);
    }
    
    index = 1;
    for(int i=1; i<t.size(); i++){
        char c = t[i];
        int flag = -1;
        for(int j=0; j<i; j++){
            if(c == t[j]) {
                flag = j;
                break;
            }
        }
        if(flag != -1) t1 += (to_string(flag)+to_string(flag));
        else           t1 += to_string(index++);
    }
    if(s1 == t1) return true;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << isIsomorphic("paper", "title") << '\n';
    cout << isIsomorphic("abcdefghijklmnopqrstuvwxyzva",
                         "abcdefghijklmnopqrstuvwxyzck") << '\n';
    return 0;
}
