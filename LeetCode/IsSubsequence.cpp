#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int sindex = 0;
    for(int tindex=0; tindex < t.size() && sindex < s.size(); tindex++){
        if(s[sindex] == t[tindex]) sindex++; //s값과 t값이 같다면 s의 인덱스를 가리키는 sindex++
    }
    return (sindex == s.size());
}

//bool isSubsequence(string s, string t) {
//    int index = 0;
//    for(int i=0; i<s.size(); i++){
//        char cur = s[i];
//        size_t pos = t.find(cur, index);
//        if(pos == string::npos || pos < index) return false; //없는 경우 || 순서가 잘못된 경우
//        t.erase(pos, 1);
//        index = pos; //index 업데이트
//    }
//    return true;
//}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << isSubsequence("aaaaaa", "bbaaaa") << '\n';
    cout << isSubsequence("axc", "ahbgdc") << '\n';
    return 0;
}
