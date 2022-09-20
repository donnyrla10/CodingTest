#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    int answer = -1;
    for(char c = 'a'; c <= 'z'; c++){
        size_t i = s.find(c);
        if(i == string::npos) continue; //이 알파벳은 문자열에 없음
        if(s.find(c, i+1) == string::npos){ //이 알파벳 다음부터 찾아보기 string::npos라면 없는 것!
            if(i < answer || answer == -1) answer = i;
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << firstUniqChar("leetcode") << '\n';
    cout << firstUniqChar("loveleetcode") << '\n';
    cout << firstUniqChar("aabb") << '\n';
    return 0;
}
