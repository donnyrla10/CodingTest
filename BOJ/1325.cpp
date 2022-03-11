#include <iostream>
#include <vector>
#include <cstring>
#define num 10002
using namespace std;
int n, m, cnt;
bool visited[num];
vector<vector<int>> computer(num);

void input(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        computer[b].push_back(a); //a가 b를 신뢰한다. b를 해킹하면 a도 해킹할 수 있다.
    }
}

void dfs(int s){
    visited[s] = true;
    ++cnt;
    for(const int &i : computer[s]){
        if(!visited[i]) dfs(i);
    }
}

void solution(){
    vector<int> answer;
    int _max = -1;
    for(int i=1; i<=n; i++){
        memset(visited, false, n + 1);
        cnt = 0;
        dfs(i);
        if(_max < cnt){
            _max = cnt;
            answer.clear(); //앞에서 최대치라고 해서 넣었던 것들 지우기
            answer.push_back(i);
        }else if(_max == cnt){
            answer.push_back(i);
        }
    }
    for(const int &i : answer) cout << i << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    input();
    solution();
    return 0;
}
