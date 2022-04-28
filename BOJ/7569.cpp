#include <iostream>
#include <queue>
#define MAX 120
using namespace std;

int H, C, R;
int box[MAX][MAX][MAX];
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}}; //위,아래,좌,우,뒤,앞
queue<pair<pair<int, int>, int>> q;

void BFS(){
    int days = 0;
    while(!q.empty()){
        int size = q.size();
        days++;
        for(int i=0; i<size; i++){
            int h = q.front().second;
            int r = q.front().first.first;
            int c = q.front().first.second;
            q.pop();
            
            for(int j=0; j<6; j++){
                int dh = h + dir[j][0];
                int dr = r + dir[j][1];
                int dc = c + dir[j][2];
                
                if(dh < H && dr < R && dc < C && dh >= 0 && dc >= 0 && dr >= 0 && box[dh][dr][dc] == 0){
                    box[dh][dr][dc] = 1; //익은 토마토로 바꿔주기
                    q.push({{dr, dc}, dh});
                }
            }
        }
    }
    //토마토 탐색
    
    //익지 않은 토마토 있는지 체크 (보관후 하루 지나야 익음)
    for(int i=0; i<H; i++){
        for(int j=0; j<R; j++){
            for(int k=0; k<C; k++){
                if(box[i][j][k] == 0){
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    cout << days-1 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> C >> R >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<R; j++){
            for(int k=0; k<C; k++){
                cin >> box[i][j][k];
                //multi-bfs(multi-root/source) - 시작점 몽땅 넣어주기
                if(box[i][j][k] == 1) q.push({{j, k}, i}); //R,C,H
            }
        }
    }
    BFS();
    return 0;
}
