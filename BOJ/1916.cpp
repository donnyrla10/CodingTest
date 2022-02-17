#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define NUM 1002
using namespace std;
int n, m, start, destination, dist[NUM];
vector<pair<int, int>> busInfo[NUM];

struct Info{
    int index, dis;
    Info(){}
    Info(int index, int dis) : index(index), dis(dis) {}
    bool operator<(const Info& in) const{
        return dis > in.dis;
    }
};

void input(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int from, to, w;
        cin >> from >> to >> w;
        busInfo[from].push_back({to, w});
    }
    cin >> start >> destination;
}

void solution(){
    priority_queue<Info> q;
    for(int i = 1; i<=n; i++) dist[i] = 0x7fffffff;     //모든 정점 초기화 -> infinite
    q.push({start, 0});     //1: index, 2: dist[]값
    dist[start] = 0;        //시작점은 0
    
    while(!q.empty()){
        Info infor = q.top();
        q.pop();
        
        if(dist[infor.index] != infor.dis) continue; //시작점에서 index까지의 거리가 dis(최신정보)와 다르면 패스
        
        //연결된 정점에 대한 정보 갱신
        for(auto& j : busInfo[infor.index]){
            auto [to, weight] = j;
            if(dist[infor.index] + weight >= dist[to]) continue;
            dist[to] = dist[infor.index] + weight;
            q.push({to, dist[to]});
        }
    }
    cout << dist[destination] << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
