#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string changeTo2(char ch){
    int x = ch - '0';
    string two = "";
    
    if(x == 0) return "0";
    
    while(x != 0){
        two += to_string(x%2);
        x /= 2;
    }
    reverse(two.begin(), two.end());
    return two;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(i==0) cout << changeTo2(str[i]);
        else{
            string tmp = changeTo2(str[i]);
            while(tmp.size() != 3)
                tmp = '0' + tmp;
            cout << tmp;
        }
    }
    return 0;
}
