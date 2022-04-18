#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int x){
    string str = to_string(x);
    int len = str.length();
    
    for(int i=0; i<len/2; i++){
        if(str[i] != str[len-1-i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << isPalindrome(121) << '\n';
    cout << isPalindrome(123) << '\n';
}
