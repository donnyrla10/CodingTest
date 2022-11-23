#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
using namespace std;

//사과를 먹으면 뱀 길이가 늘어난다. 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.
//NxN보드 위, 사과가 놓여져있고, 보드의 상하좌우 끝에 벽이 있다.
//게임이 몇 초에 끝나는지 계산
//사과1, 빈칸0
//뱀머리위치 x y, 방향 d

//좌측 상단에서 뱀이 위치하고 뱀의 길이는 1. 처음엔 오른쪽을 향한다.
//1. 몸 길이를 늘려 머리를 다음칸에 위치
//2. 이동한 칸에 사과가 있다면, 그 칸에 있던 사과는 없어지고 꼬리는 움직이지 않음
//3. 이동한 칸에 사과가 없다면, 몸길이를 줄여 꼬리가 위치한 칸을 비워준다. 몸길이는 변하지 않음

int n, k, l;
int x = 1, y = 1, d = 0;
int tx = 1, ty = 1; //꼬리 x, y
int arr[101][101];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int timeSnake = 1;
queue<pair<int, int>> snake;
queue<pair<int, char>> v;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    arr[1][1] = 2;
    snake.push({1, 1}); //뱀 꼬리
    bool finish = false;
    while(k--){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1; //사과
    }
    cin >> l;
    while(l--){
        int z; char c;
        cin >> z >> c;
        v.push({z, c});
    }
    while(1){
        //앞으로 전진
        int dx = x + dir[d][0];
        int dy = y + dir[d][1];
        //이동한 칸이 벽이거나 자신이면 게임 끝
        if((0>=dx||dx>n||0>=dy||dy>n) || arr[dx][dy] == 2) {
            cout << timeSnake << '\n';
            finish = true; //게임 끝
            break;
        }
        //2. 이동한 칸에 사과가 있다면, 그 칸에 있던 사과는 없어지고 꼬리는 움직이지 않음
        //3. 이동한 칸에 사과가 없다면, 몸길이를 줄여 꼬리가 위치한 칸을 비워준다. 몸길이는 변하지 않음
        if(arr[dx][dy] != 1) { //사과가 없다면
            arr[snake.front().first][snake.front().second] = 0; //꼬리 위치칸 0으로 변경 -> 꼬리 비워줌
            snake.pop();
        }
        arr[dx][dy] = 2;      //뱀 길이 추가
        snake.push({dx, dy}); //뱀 길이 추가
        x = dx; y = dy;       //뱀 머리 이동
        timeSnake++;
        if(!v.empty() && timeSnake - 1 == v.front().first) { //rotate
            d = v.front().second == 'L' ? (4+(d-1))%4 : (d+1)%4;
            v.pop(); //회전하는 경우 pop
        }
    }
    return 0;
}
