#include <iostream>
#include <vector>
using namespace std;

int del;
vector<int> tree[50];

int DFS(int x){
    int child = 0;
    
    for(auto ch : tree[x]){
        if(ch == del) continue;
        child += DFS(ch);
    }
    
    if(child) return child;
    else      return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, root = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        if(p==-1) root = i;
        else      tree[p].push_back(i);
    }
    cin >> del;
    if(root != del) cout << DFS(root) << '\n';
    else            cout << "0\n";
    
    return 0;
}
