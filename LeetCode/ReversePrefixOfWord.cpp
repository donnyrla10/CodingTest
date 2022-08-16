#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string reversePrefix(string word, char ch) {
    size_t index = word.find(ch);
    if(index == string::npos) return word;
    reverse(word.begin(), word.begin()+index+1);
    return word;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << reversePrefix("abcd", 'z') << '\n';
    return 0;
}
