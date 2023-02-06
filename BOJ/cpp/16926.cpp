#include <iostream>
#include <algorithm>
#define MAX 301
using namespace std;
int r, c, t, arr[MAX][MAX];

void Rotation(){
    int depth = (min(r, c) / 2) + (min(r, c) % 2);
    
    for(int i=0; i<depth; i++){
        int curx = i; int cury = i;
        int cur = arr[curx][cury];
        
        //left부분은 아래로 이동
        while(curx < r - 1 - i){
            int next = arr[curx+1][cury]; //아래 값
            arr[curx+1][cury] = cur; //아래칸에 현재 값 넣기
            cur = next; //현재값에 아래값 넣기
            curx++; //아래로 이동
        }
        //btm부분은 오른쪽으로 이동
        while(cury < c - 1 - i){
            int next = arr[curx][cury+1]; //오른쪽 값
            arr[curx][cury+1] = cur;
            cur = next;
            cury++;
        }
        //right부분은 위로 이동
        while(curx >= i+1){
            int next = arr[curx-1][cury];
            arr[curx-1][cury] = cur;
            cur = next;
            curx--;
        }
        //top부분은 왼쪽으로 이동
        while(cury >= i+1){
            int next = arr[curx][cury-1];
            arr[curx][cury-1] = cur;
            cur = next;
            cury--;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> t;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin >> arr[i][j];
    while(t--) Rotation();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
