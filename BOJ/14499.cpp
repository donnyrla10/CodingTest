#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
using namespace std;

//NxM지도
//초기 주사위 모든 면: 0
//지도의 각 칸에 정수가 쓰여져 있다.
//이동한 칸에 쓰여진 수가 0이면 주사위 바닥면에 쓰여있는 수가 칸에 복사된다.
//이동한 칸에 쓰인 수가 0이 아닌 경우, 칸에 쓰여있는 수가 주사위의 바닥면으로 복사. 칸에 쓰인 수는 0이 된다.
//주사위가 이동했을 때마다 상단(윗면)에 쓰여있는 값을 구하는 프로그램

int n, m, x, y, k;
int arr[21][21];
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}}; //동:1, 서:2, 북:3, 남:4
int dice[4][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> arr[i][j];
    while(k--){
        int com;
        cin >> com;
        //해당 방향으로 이동가능한지 체크
        int dx = x + dir[com][0];
        int dy = y + dir[com][1];
        if(0 > dx || dx >= n || 0 > dy || dy >= m) continue; //바깥으로 이동하는 경우는 패스
        //주사위 굴리기 -> 상/하단 좌표 변경해주기
        if(com == 1){ //동
            int tmp = dice[1][2];
            dice[1][2] = dice[1][1];
            dice[1][1] = dice[1][0];
            dice[1][0] = dice[3][1];
            dice[3][1] = tmp;
        }else if(com == 2){ //서
            int tmp2 = dice[1][0];
            dice[1][0] = dice[1][1];
            dice[1][1] = dice[1][2];
            dice[1][2] = dice[3][1];
            dice[3][1] = tmp2;
        }else if(com == 3){ //북
            int tmp = dice[0][1];
            for(int i=0; i<3; i++) dice[i][1] = dice[i+1][1];
            dice[3][1] = tmp;
        }else if(com == 4){ //남
            int tmp = dice[3][1];
            for(int i=3; i>0; i--) dice[i][1] = dice[i-1][1];
            dice[0][1] = tmp;
        }
        //해당 좌표의 값 확인하기
        //0이면 주사위 바닥면의 값을 해당 좌표에 넣기
        //0이 아니면 좌표의 값을 바닥면에 넣고, 좌표의 값은 0으로 변경
        if(arr[dx][dy] == 0){
            arr[dx][dy] = dice[3][1];
        } else {
            dice[3][1] = arr[dx][dy];
            arr[dx][dy] = 0;
        }
        //주사위 상단top의 값 출력
        cout << dice[1][1] << '\n';
        x = dx; y = dy;
    }
    return 0;
}
