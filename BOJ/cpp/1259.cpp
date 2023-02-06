#include <iostream>
#include <string>
using namespace std;
string s;
int len;

bool check(){
    for(int i=0; i<len/2; i++){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(1){
        cin >> s;
        len = s.size();
        if(s == "0") break;
        if(check()) cout << "yes\n";
        else        cout << "no\n";
    }
    return 0;
}
