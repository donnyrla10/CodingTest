#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    ans[0].push_back(1);
    
    for(int i=1; i<numRows; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i) ans[i].push_back(1);
            else             ans[i].push_back((ans[i-1][j-1]+ans[i-1][j]));
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> ans = generate(5);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
