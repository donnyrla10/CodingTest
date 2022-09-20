#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int findContentChildren(vector<int> g, vector<int> s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int gin = 0, sin = 0, res = 0;
    while(gin < g.size() && sin < s.size()){
        if(g[gin] <= s[sin]){
            res++; gin++; sin++;
        }else {
            sin++;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << findContentChildren({1,2,3}, {1,1}) << '\n';
//    cout << findContentChildren({1,2}, {1,2,3}) << '\n';
    return 0;
}
