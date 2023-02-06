#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1000001
using namespace std;

int f, s, g, u, d;
int visited[MAX];

void bfs(){
    queue<int> q;
    q.push(s);
    visited[s] = 0;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(x == g){
            cout << visited[x] << '\n';
            return;
        }
        
        for(int i=0; i<2; i++){
            int dx;
            if(i==0) dx = x + u;
            else     dx = x - d;
            
            if(dx > f || dx <= 0) continue;
            if(visited[dx] >= 0) continue;
            visited[dx] = visited[x] + 1;
            q.push(dx);
        }
    }
    cout << "use the stairs\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> f >> s >> g >> u >> d;
    for(int i=1; i<=f; i++) visited[i] = -1;
    bfs();
    return 0;
}
