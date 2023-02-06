#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for(int i=0; i<s.size()/2; i++){
        if(s[i] != s[s.size()-1-i]){
            cout << "0\n";
            return 0;
        }
    }
    cout << "1\n";
    return 0;
}
