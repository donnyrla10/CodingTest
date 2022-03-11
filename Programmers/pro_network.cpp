#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
bool visited[202];
using namespace std;

void bfs(int s, vector<vector<int>> graph){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int j : graph[x]){
            if(visited[j]) continue;
            q.push(j);
            visited[j] = true;
        }
    }
}

void dfs(int x, const vector<vector<int>> com){
    visited[x] = true;
    
    for(int i=0; i<com[x].size(); i++){
        if(com[x][i] == 1 && !visited[i]) dfs(i, com);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    memset(visited, false, n+1);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, computers);
            //bfs(i, computers);
            answer++;
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution(3, {{1,1,0}, {1,1,1}, {0,1,1}}) << '\n';
    return 0;
}
