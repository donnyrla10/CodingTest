#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string reverseStr(string s, int k) {
    int sindex = 0, eindex = s.size();
    
    while(sindex < s.size()){
        int rest = eindex - sindex; //남은 문자열 길이
        if(2 * k > rest){ //2k보다 짧음
            if(k <= rest){ //k보단 크거나 같은 문자열 -> reverse first k char
                reverse(s.begin()+sindex, s.begin()+sindex+k);
                break;
            }else { //k보다 작은 문자열 -> reverse all of them
                reverse(s.begin()+sindex, s.end());
                break;
            }
        }else{ //2k보다 크거나 같음 -> reverse first k char
            eindex = sindex + 2 * k - 1;
            reverse(s.begin()+sindex, s.begin()+sindex+k);
            sindex = eindex + 1; //시작 위치 업데이트
            eindex = s.size();
        }
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << reverseStr("abcdefg", 2) << '\n';
//    cout << reverseStr("abcd", 2) << '\n';
    return 0;
}
