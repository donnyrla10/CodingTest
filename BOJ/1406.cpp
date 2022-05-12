#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    stack<char> left;  //커서의 왼쪽
    stack<char> right; //커서의 오른쪽
    int n;
    cin >> str >> n;
    for(int i=0; i<str.size(); i++) left.push(str[i]);
    
    while(n--){
        char com;
        cin >> com;
        
        if(com == 'L'){
            //만약에 커서가 맨 앞에 있으면 무시 -> left 스택에 아무것도 없으면 패스
            if(left.empty()) continue;
            //왼쪽 top에 잇는게 오른쪽 스택으로 이동
            right.push(left.top());
            left.pop();
        }else if(com == 'D'){
            if(right.empty()) continue;
            left.push(right.top());
            right.pop();
        }else if(com == 'B'){
            if(left.empty()) continue;
            left.pop();
        }else if(com == 'P'){
            char al;
            cin >> al;
            left.push(al);
        }
    }
    
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }
    cout << '\n';
    return 0;
}
