#include <iostream>
#include <queue>
#include <vector>
#define MAX 32002
using namespace std;
int n, m, a, b, indegree[MAX];
vector<int> graph[MAX];
queue<int> q;

void input(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;          //들어오는 간선 개수 카운팅
    }
}

void solution(){
    for(int i=1; i<=n; i++) if(indegree[i] == 0) q.push(i); //들어오는 간선이 0개인 정점, 큐에 넣기
        
    while(!q.empty()){
        int x = q.front();
        q.pop();                            //x 꺼내기
        cout << x << ' ';
        for(int j : graph[x]){              //graph에서 x 와 연결된 애들을 찾아서 제거해줘야 함
            indegree[j]--;                  //들어오는 간선 개수 --
            if(indegree[j] == 0) q.push(j); //새로운 정점, 큐에 삽입
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
