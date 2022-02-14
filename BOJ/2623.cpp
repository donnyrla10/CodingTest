#include <iostream>
#include <vector>
#include <queue>
#define MAX 1002
using namespace std;
int n, m, indegree[MAX];
vector<int> graph[MAX];
vector<int> ans;

void input(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int cnt, x, y;
        cin >> cnt;
        cin >> x;
        for(int j=2; j<= cnt; j++){
            cin >> y;
            graph[x].push_back(y);
            indegree[y]++;
            x = y;
        }
    }
}

void solution(){
    queue<int> q;
    for(int i=1; i<=n; i++) if(indegree[i] == 0) q.push(i);
    while(!q.empty()){
        int x = q.front();
        ans.push_back(x);
        q.pop();
        for(int i: graph[x]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    if(ans.size() != n) cout << 0; //순서를 정하지 못한 경우
    else for(auto it = ans.begin(); it!=ans.end(); it++) cout << *it << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
