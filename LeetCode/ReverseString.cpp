#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    reverse(s.begin(), s.end());
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<char> ans = {'h', 'e', 'l', 'l', 'o'};
    reverseString(ans);
    return 0;
}
