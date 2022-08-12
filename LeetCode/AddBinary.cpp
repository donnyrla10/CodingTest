#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    string answer = "";
    char c = '0';
    if(a.size() > b.size()){
        for(int i=b.size(); i<a.size(); i++) b = '0' + b;
    }else if(a.size() < b.size()){
        for(int i=a.size(); i<b.size(); i++) a = '0' + a;
    }
    
    for(int i=a.size()-1; i>=0; i--){
        char x;
        if(a[i] == b[i] && b[i] == '1'){
            x = (c == '1') ? '1' : '0';
            c = '1';
            answer = x + answer;
        }else if(a[i] == b[i] && b[i] == '0'){
            x = (c == '1') ? '1' : '0';
            c = '0';
            answer = x + answer;
        }else{
            x = (c == '1') ? '0' : '1';
            c = (c == '1') ? '1' : '0';
            answer = x + answer;
        }
    }
    if(c == '1') answer = '1' + answer;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << addBinary("110", "1011") << '\n';
    return 0;
}
