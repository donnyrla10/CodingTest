#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int answer = 0;
    
    size_t nPos = haystack.find(needle);
    if(nPos == string::npos) return -1;
    else answer = nPos;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << strStr("aaaaa", "ba") << '\n'; //2
    
    return 0;
}
