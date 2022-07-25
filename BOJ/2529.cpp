#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int k;
char ch[10];
vector<string> v;
string s;
bool visit[10];

bool check(){
    for(int i=0; i<k; i++){
        if(ch[i] == '>' && s[i] < s[i+1]) return false;
        if(ch[i] == '<' && s[i] > s[i+1]) return false;
    }
    return true;
}

void backtracking(int cnt){
    if(cnt == k+1){
        if(check()) v.push_back(s);
        return;
    }
    
    for(int i=0; i<10; i++){
        if(!visit[i]){
            visit[i] = true;
            s += to_string(i);
            backtracking(cnt+1);
            s = s.substr(0, s.size()-1);
            visit[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k;
    for(int i=0; i<k; i++) cin >> ch[i];
    backtracking(0);
    sort(v.begin(), v.end());
    cout << v[v.size()-1] << '\n' << v[0] << '\n';
    return 0;
}
