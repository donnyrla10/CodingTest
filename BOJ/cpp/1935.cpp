#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

double calculate(char op, double a, double b){
    if(op == '+') return b+a;
    else if(op == '-') return b-a;
    else if(op == '*') return b*a;
    else return b/a;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    int num[27];
    stack<double> st;
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> num[i]; //1 2 3 4 5

    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c <= 'Z' && c >= 'A'){ //알파벳이라면
            st.push(num[c-'A']);
        }else{
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(calculate(c, a, b));
        }
    }
    printf("%.2lf\n", st.top());
    return 0;
}
