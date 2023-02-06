#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s = "cdcd";
    int answer = -1;
    stack<int> st;
    if(s.empty() || s.size()%2 == 1) answer = 0;
    
    for(int i=0; i<s.size(); i++){
        if(st.empty() || st.top() != s[i]){
            st.push(s[i]);
        }else{
            st.pop();
        }
    }
    
    if(st.empty()) answer = 1;
    else           answer = 0;
    cout << answer << '\n';
    return 0;
}
