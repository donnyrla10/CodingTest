#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    int ans = 0;
    vector<int> v;
    vector<int> op;
    vector<char> op2;
    cin >> s;
    
    string tmp = "";
    bool isMinus = false;
    
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            tmp += s[i];
        }else{
            op.push_back(stoi(tmp));
            tmp = "";
            op2.push_back(s[i]);
        }
    }
    op.push_back(stoi(tmp));
    
    ans = op[0];
    for(int i=0; i<op2.size(); i++){
        if(op2[i] == '-'){
            isMinus = true;
            ans -= op[i+1];
        }
        if(op2[i] == '+'){
            if(!isMinus) ans += op[i+1];
            else         ans -= op[i+1];
        }
    }
    cout << ans << '\n';
    return 0;
}
