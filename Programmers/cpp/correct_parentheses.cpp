#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool solution(string s){
    bool answer = true;
    stack<char> st;
    
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c == '('){
            st.push(c);
        }else if(c == ')'){
            if(st.empty()) return false;
            if(st.top() == '('){
                st.pop();
            }else{
                st.push(')');
            }
        }
    }
    if(!st.empty()) answer = false;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution("()()") << '\n';
//    cout << solution("(())()") << '\n';
//    cout << solution(")()(") << '\n';
    cout << solution("(()(") << '\n';
    return 0;
}
