#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    stack<pair<int, int>> s; //index, height
    int n, h;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> h;
        while(!s.empty()){
            if(s.top().second > h){
                cout << s.top().first << ' ';
                break;
            }
            s.pop();
        }
        if(s.empty()) cout << "0 ";
        s.push({i, h});
    }
    return 0;
}
