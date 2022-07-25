#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    for(int i=2; i<n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    while(1){
        string s = to_string(n);
        bool flag = false;
        for(int i=0; i<s.size()/2; i++){
            if(s[i] != s[s.size()-1-i]) {
                flag = true;
                break; //팰린드롬아님
            }
        }
        if(!flag && isPrime(n)){
            cout << n << '\n';
            break;
        }
        n++;
    }
    return 0;
}
