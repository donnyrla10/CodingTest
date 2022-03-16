#include <iostream>
#define MAX 11
using namespace std;
int r, c;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char map[MAX][MAX];

//50년이 지나면, 인접한 세칸 또는 네칸에 바다가 있는 땅은 모두 잠겨벼린다.
//섬의 개수가 오늘날보다 적어질 것이기 때문에, 지도의 크기도 작아져야 한다.
//지도의 크기는 모든 섬을 포함하는 가장 작은 직사각형
//지도에 없는 곳, 지도를 벗어나는 칸은 모두 바다

void input(){
    cin >> r >> c;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin >> map[i][j];
}

void solution(){
    char tmp[MAX][MAX];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) tmp[i][j] = map[i][j];
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] == 'X'){ //주변 체크하기
                int cnt = 0;
                for(int k=0; k<4; k++){
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if(ni<0||nj<0||ni>=r||nj>=c||map[ni][nj] == '.') cnt++;
                }
                if(cnt == 3 || cnt == 4) tmp[i][j] = '.';
            }
        }
    }

    int sr=-1, er=-1, sc=-1, ec=-1;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(tmp[i][j] == 'X'){
                if(sr==-1){ sr = i; break;}
            }
        }
    }
    for(int i=r-1; i>=0; i--){
        for(int j=0; j<c; j++){
            if(tmp[i][j] == 'X'){
                if(er==-1){ er = i; break;}
            }
        }
    }
    for(int i=0; i<c; i++){ //0 - 9
        for(int j=0; j<r; j++){ //0 1 2
            if(tmp[j][i] == 'X'){
                if(sc==-1){ sc = i; break;}
            }
        }
    }
    for(int i=c-1; i>=0; i--){ //0 - 9
        for(int j=0; j<r; j++){ //0 1 2
            if(tmp[j][i] == 'X'){
                if(ec==-1){ ec = i; break;}
            }
        }
    }
    
    for(int i=sr; i<=er; i++){
        for(int j=sc; j<=ec; j++){
            cout << tmp[i][j];
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}

