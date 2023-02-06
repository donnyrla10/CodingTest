#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
bool ans = false;
vector<int> graph[2001];

void DFS(int x, int cnt, vector<bool> &visit){
    visit[x] = true;
    if(cnt == 4){
        ans = true;
        return;
    }
    
    for(int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if(!visit[y]) DFS(y, cnt+1, visit);
    }
    visit[x] = false;
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=0; i<n; i++){
        vector<bool> visit(n);
        DFS(i, 0, visit);
        if(ans){
            cout << "1\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}
