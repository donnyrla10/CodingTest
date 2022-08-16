#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> digits) {
    bool c = true; //1은 올림수
    for(int i=digits.size()-1; i>=0; i--){
        int n = digits[i];
        if(c == false) break;
        if(n + 1 > 9){
            digits[i] = 0;
            c = true;
        }else{
            digits[i] = n + 1;
            c = false;
        }
    }
    if(c == true) {
        digits.push_back(1);
        reverse(digits.begin(), digits.end());
    }
    return digits;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> ans = plusOne({9,9,8});
    for(auto i: ans) cout << i << ' ';
    cout << '\n';
    return 0;
}
