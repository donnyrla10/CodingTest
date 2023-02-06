#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string swapChar(string s){
    string tmp = s;
    for(int i=0; i<tmp.size()/2; i++){
        swap(tmp[i], tmp[tmp.size()-i-1]);
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, ans;
    getline(cin, s);
    string tmp;
    bool flag = false;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '<'){
            flag = true;
            ans += '<';
            tmp = "";
        }else if(s[i] == '>'){
            flag = false;
            ans += '>';
        }else{
            if(flag){ //괄호 열린 상태
                ans += s[i]; //그냥 문자 넣음
            }else{
                if(s[i] != ' '){ //문자
                    tmp += s[i];
                }else if(s[i] == ' '){ //빈칸
                    //뒤집기
                    ans += swapChar(tmp) + ' ';
                    tmp = "";
                }
                if(s[i+1] == '<') {
                    ans += swapChar(tmp);
                }
            }
        }
    }
    if(ans.size() != s.size()) ans += swapChar(tmp);
    cout << ans << '\n';
    return 0;
}
