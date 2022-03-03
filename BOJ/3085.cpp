#include <iostream>
#include <algorithm>
#define num 52
using namespace std;
int n, cnt=0;
char candy[num][num];

//사탕의 색이 다른 인접한 두 칸을 고른다.
//고른 칸에 들어있는 사탕을 서로 교환
//모두 같은 색으로 이루어져 있는 가장 긴 연속 부분을 고른다음 그 사탕을 모두 먹는다.
//상근이가 먹을 수 있는 사탕의 최대 개수를 구하라.

//완전탐색으로 생각해보기

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> candy[i][j];
}

void CountingCandy(){
    //행
    for(int i=1; i<=n; i++){
        int tmp = 1;
        for(int j=1; j<n; j++){
            if(candy[i][j] == candy[i][j+1]){
                tmp++;
                cnt = max(tmp, cnt);
            }else{
                tmp = 1;
            }
        }
    }
    
    //열
    for(int j=1; j<=n; j++){
        int tmp = 1;
        for(int i=1; i<n; i++){
            if(candy[i][j] == candy[i+1][j]){
                tmp++;
                cnt = max(tmp, cnt);
            }else{
                tmp = 1;
            }
        }
    }
}

void solution(){
    //가로 swap 의 경우
    for(int i=1; i<=n; i++){
        for(int j=1; j<n; j++){
            swap(candy[i][j], candy[i][j+1]);
            CountingCandy();
            swap(candy[i][j], candy[i][j+1]); //초기화
        }
    }
    
    //세로 swap 의 경우
    for(int j=1; j<=n; j++){
        for(int i=1; i<n; i++){
            swap(candy[i][j], candy[i+1][j]);
            CountingCandy();
            swap(candy[i][j], candy[i+1][j]); //초기화
        }
    }
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
