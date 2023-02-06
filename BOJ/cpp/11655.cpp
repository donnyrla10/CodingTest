#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c >= 'a' && c <= 'z'){
            if(c - 'a' < 13) c += 13;
            else             c -= 13;
        }else if(c >= 'A' && c <= 'Z'){
            if(c - 'A' < 13) c += 13;
            else             c -= 13;
        }
        s[i] = c;
    }
    cout << s << '\n';
    return 0;
}
