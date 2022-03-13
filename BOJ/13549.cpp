#include <iostream>
#include <queue>
#define num 100001
#define INF 999999999
using namespace std;
int n, k;
int dist[num];

//수빈N 동생K
//이동 방법
//1. x-1 or x+1 (1초후에)
//2. x*2 (0초후에)
//수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인가?

void bfs(){
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur == k) { //동생에게 도착했으면 끝
            cout << dist[k] << '\n';
            break;
        }
        
        for(int i=0; i<3; i++){
            int dir[3] = {cur*2, cur+1, cur-1};
            int next = dir[i];
            int time;
            if(i == 0) time = 0;
            else       time = 1;
            
            //시작점에서 바로 next로 가기 vs. 현재위치에서 next로 가기
            if(next >= 0 && next < num && dist[next] > dist[cur] + time){
                q.push(next);
                dist[next] = dist[cur] + time;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<num; i++) dist[i] = INF;
    bfs();
    return 0;
}
