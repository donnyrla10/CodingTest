#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int n, k, arr[11];
set<int> num;
bool ch[11];

void backtracking(int cnt, string s){
    if(cnt == k){
        num.insert(stoi(s)); //중복은 알아서 제거
        return;
    }
    
    for(int i=0; i<n; i++){
        if(!ch[i]){
            ch[i] = true;
            string ss = s + to_string(arr[i]);
            backtracking(cnt+1, ss);
            ch[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    backtracking(0, "");
    
    cout << num.size() << '\n';
    return 0;
}
