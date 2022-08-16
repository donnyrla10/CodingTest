#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> ans(rowIndex+1);
    ans[0].push_back(1);
    for(int i=1; i<=rowIndex; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i) ans[i].push_back(1);
            else             ans[i].push_back((ans[i-1][j-1]+ans[i-1][j]));
        }
    }
    return ans[rowIndex];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> ans = getRow(0);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
