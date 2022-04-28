#include <iostream>
#include <vector>
#include <cstring>
#define MAX 102
using namespace std;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int x){
    visited[x] = true;
    for(int i=0; i<graph[x].size(); i++){
        int next = graph[x][i];
        if(!visited[next]) dfs(next);
    }
}

int distance(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    
    while(t--){
        //초기화
        memset(visited, false, sizeof(visited));
        for(int i=0; i<MAX; i++) graph[i].clear();
        vector<pair<int, int>> coord;
        
        int x, y;
        cin >> n; //편의점 개수
        
        for(int i=0; i<n+2; i++){
            cin >> x >> y;
            coord.push_back({y, x});
        }
                
        //맥주 20병으로 갈 수 있는 거리에 있으면 그래프에 추가
        //20병으로 갈 수 있는 곳만 이동한다!
        for(int i=0; i<n+2; i++){
            for(int j=i+1; j<n+2; j++){
                if(distance(coord[i], coord[j]) <= 1000){ //이동거리가 1000미터 이하면 가능
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        dfs(0);
        
        if(visited[n+1]) cout << "happy\n";
        else             cout << "sad\n";
    }
    
    return 0;
}
