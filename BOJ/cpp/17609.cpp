#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkP(string s){
    int l = 0, r = s.size()-1;
    while(l<r){
        if(s[l] != s[r]) return false;
        else{
            l++; r--;
        }
    }
    return true;
}

void ccheck(string s){
    int l = 0, r = s.size() - 1;
    while(l<r){
        if(s[l] != s[r]){
            string ori = s;
            string t1 = s.erase(l, 1); //l기준 앞부분 한 글자 삭제
            string t2 = ori.erase(r, 1); //r기준 뒷부분 한 글자 삭제
            if(checkP(t1) || checkP(t2)) cout << 1 << '\n';
            else                         cout << 2 << '\n'; //l, r 둘다 지워봤는데 같지 않으면 2 출력
            return;
        }else{
            r--; l++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        string s;
        cin >> s;
        if(checkP(s)) cout << 0 << '\n';
        else          ccheck(s);
    }
    
    return 0;
}
