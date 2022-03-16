#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    getline(cin, str);
    
    while(str != "END"){
        reverse(str.begin(), str.end());
        cout << str << '\n';
        getline(cin, str);
    }
    return 0;
}
