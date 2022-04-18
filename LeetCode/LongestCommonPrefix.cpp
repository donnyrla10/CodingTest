#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string> strs){
    string answer = "";
    for(int i=0; i<strs[0].size(); i++){
        for(int j=1; j<strs.size(); j++){
            if(strs[0][i] != strs[j][i]) return answer;
        }
        answer += strs[0][i];
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << longestCommonPrefix({"flower", "flow", "flight"}) << '\n';
    cout << longestCommonPrefix({"dog","racecar","car"}) << '\n';
}
