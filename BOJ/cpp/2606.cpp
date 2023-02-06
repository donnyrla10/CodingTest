#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int n, p, a, b, cnt=-1;
vector<int> graph[101];
bool visited[101] = {false};

void input(){
    cin >> n >> p;
    for(int i=0; i<p; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int x){
    cnt++;
    visited[x] = true;
    for(int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    clock_t start, end;
    start = clock();
    dfs(1);
    end = clock();
    cout << (double)(end-start) * 0.01 << '\n';
    cout << cnt << '\n';
    return 0;
}
