#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string firstPalindrome(vector<string> words) {
    string answer = "";
    for(int i=0; i<words.size(); i++){
        string s = words[i];
        int l=0, r=s.size()-1;
        bool f = false;
        while(l<r){
            if(s[l] != s[r]) {
                f = true;
                break;
            }else{
                l++; r--;
            }
        }
        if(!f) return s;
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << firstPalindrome({"abc","car","ada","racecar","cool"}) << '\n';
    cout << firstPalindrome({"notapalindrome","racecar"}) << '\n';
    cout << firstPalindrome({"def","ghi"}) << '\n';
    return 0;
}
