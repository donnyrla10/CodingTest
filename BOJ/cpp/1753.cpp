#include <iostream>
#include <queue>
#include <vector>
#define NUM 20002
#define INF 0x7fffffff
using namespace std;
int V, E, K, dist[NUM];
vector<pair<int, int>> graph[NUM];

struct Info{
    int index;
    int dis;
    Info(){}
    Info(int index, int dis) : index(index), dis(dis) {}
    bool operator<(const Info& inf) const{
        return dis > inf.dis;
    }
};

void input(){
    cin >> V >> E;
    cin >> K;       //시작점 K
    for(int i=0; i<E; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }
}

void solution(){
    priority_queue<Info> pq;
    for(int i=1; i<=V; i++) dist[i] = INF;
    pq.push({K, 0});
    dist[K] = 0;

    //연결된 정점 돌면서 갱신하기
    while(!pq.empty()){
        Info info = pq.top(); pq.pop();

        //갱신된(아닐수있음) 값과 시작점에서 현재 정점의 거리를 비교해서 동일하지 않으면 패스
        if(dist[info.index] != info.dis) continue;

        for(auto& i: graph[info.index]){ //info.index == info 정점의 인덱스, i = info의 연결된 정점
            auto [index, weight] = i;    //index == 연결 정점의 인덱스, weight == 연결 정점의 값(갱신될것)
            if(dist[index] <= dist[info.index] + weight) continue;
            dist[index] = dist[info.index] + weight; //정점의 거리 갱신
            pq.push({index, dist[index]});           //연결 정점 우선순위 큐에 추가
        }
    }

    for(int i=1; i<=V; i++){
        dist[i] == INF ? cout << "INF\n" : cout << dist[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}

