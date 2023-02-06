#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    int answer = 0;
    stack<char> st;
    cin >> s;
    
    for(int i=0; i<s.length(); i++){
        if(i+1 < s.length() && s[i] == '(' && s[i+1] == ')'){ //레이저
            if(!st.empty()) answer += st.size(); //안에 쇠막대기가 있다면
            i++;
        }else if(s[i] == '('){ //맨 위에 쇠막대기 넣기
            st.push(s[i]);
        }else if(s[i] == ')'){ //맨 위 쇠막대기 끝남
            st.pop();
            answer++; //나오면서 나머지 하나 추가
        }
    }
    cout << answer << '\n';
    return 0;
}
