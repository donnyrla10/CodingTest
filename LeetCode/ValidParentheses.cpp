#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s = ")";
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }else if(c == ')'){
            if(st.empty() || st.top() == '{' || st.top() == '[') {
                cout << false << '\n';
                return 0;
            }
            if(st.top() == '(') st.pop();
            else st.push(')');
        }else if(c == ']'){
            if(st.empty() || st.top() == '{' || st.top() == '(') {
                cout << false << '\n';
                return 0;
            }
            if(st.top() == '[') st.pop();
            else st.push(']');
        }else if(c == '}'){
            if(st.empty() || st.top() == '(' || st.top() == '[') {
                cout << false << '\n';
                return 0;
            }
            if(st.top() == '{') st.pop();
            else st.push('}');
        }
    }
    if(!st.empty()) cout << false << '\n';
    else            cout << true << '\n';;
    return 0;
}
