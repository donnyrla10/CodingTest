#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    int ans = 0;
    cin >> n;
    while(n--){
        string s;
        stack<char> st;
        cin >> s;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(st.empty()){
                st.push(c);
            }else{
                if(st.top() == c) st.pop();
                else st.push(c);
            }
        }
        if(st.empty()) ans++;
    }
    cout << ans << '\n';
    return 0;
}
