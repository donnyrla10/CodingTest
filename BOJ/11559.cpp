#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

string arr[12];
bool visit[12][6]; //중복 방지 (방문체크)
bool boom; //터졌는지에 대한 여부
int ans;
vector<pair<int, int>> coor;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void Boom(int a, int b){
    queue<pair<int, int>> q;
    visit[a][b] = true;
    q.push({a, b});
    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        coor.push_back({x, y});
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0<=dx&&dx<12&&0<=dy&&dy<6&&arr[dx][dy] == arr[x][y] &&!visit[dx][dy]){
                visit[dx][dy] = true;
                q.push({dx, dy});
            }
        }
    }
    if(coor.size() >= 4) {
        boom = true; //4개 이상이 연결되어있으면 터짐
        for(auto i:coor) arr[i.first][i.second] = '.'; //터진애들
    }
    coor.clear();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0; i<12; i++) cin >> arr[i];
    do {
        boom = false; //초기화
        for(int i=0; i<6; i++){ //빈칸(.)을 뿌요 위로 올린다.
            for(int j=10; j>=0; j--){
                int tmp = j;
                while(tmp<11&&arr[tmp+1][i]=='.') { //밑 원소가 . 이라면 바꾼다
                    swap(arr[tmp][i], arr[tmp+1][i]);
                    tmp++;
                }
            }
        }
        //뿌요 터트리기
        for(int i=0; i<12; i++)
            for(int j=0; j<6; j++)
                if(!visit[i][j] && arr[i][j] != '.') Boom(i, j);
        //터졌으면 카운팅++
        if(boom) ans++;
        for(int i=0; i<12; i++) fill(visit[i], visit[i]+6, false);
    }while(boom); //터지면 계속 반복 -> 터지지 않으면 중단
    cout << ans << '\n';
    return 0;
}

//......
//......
//......
//......
//......
//......
//......
//......
//.Y....
//.YG...
//RRYG..
//RRYGG.
