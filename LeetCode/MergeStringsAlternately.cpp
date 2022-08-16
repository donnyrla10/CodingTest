#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string answer = "";

    int index = 0;
    while(1){
        if(word2.size() <= index || word1.size() <= index) break;
        answer += word1[index];
        answer += word2[index];
        index++;
    }
    if(word1.size() > word2.size())      answer += word1.substr(index);
    else if(word1.size() < word2.size()) answer += word2.substr(index);
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << mergeAlternately("abc", "pqr") << '\n';
//    cout << mergeAlternately("ab", "pqrs") << '\n';
//    cout << mergeAlternately("abcd", "pq") << '\n';
    return 0;
}
