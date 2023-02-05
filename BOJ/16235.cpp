#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;
int A[11][11];
int arr[11][11];
deque<int> tree[11][11];

void input() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> A[i][j];
            arr[i][j] = 5;
        }
    }
    for(int i=0; i<m; i++){
        int x, y, a;
        cin >> x >> y >> a;
        tree[x][y].push_back(a);
    }
}

void spring_summer(){
    //모든 나무는 age만큼 양분을 먹고(arr 양분 -= age), 해당 나무 나이 + 1
    //만약 한 칸에 여러 나무 -> 어린 나무 먼저 양분 먹기
    //양분 나이만큼 못먹으면 죽음
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int k = 0;
            int size = tree[i][j].size();
            for(;k<size; ++k) {
                if(tree[i][j][k] > arr[i][j]) { //나이가 양분보다 많으면 죽음
                    break; //뒤에 애들 다 양분보다 나이가 많을 테니
                }else {
                    arr[i][j] -= tree[i][j][k]; //양분이 나이만큼 없어짐
                    tree[i][j][k] += 1; //나이 한살 더 먹음
                }
            }
            //여름: 죽은 나무 처리
            //죽은 나무 마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가
            //봄에서 진행한 칸은 이미 실행끝나서 여기에 양분 추가해도 괜찮음
            for(int p = size-1; p>= k; --p){
                arr[i][j] += tree[i][j][p]/2;
                tree[i][j].pop_back();
            }
        }
    }
}

void autumn_winter(){
    //나무 번식
    //번식할 수 있는 나무는 나이가 5의 배수. 인접 8칸에 나이가 1인 나무 추가 (앞에 추가해야 됨)
    int direction[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(tree[i][j].size() > 0) { //나무가 있는 칸만 체크
                for(int k=0; k<tree[i][j].size(); k++){
                    if(tree[i][j][k] % 5 == 0){ //나무의 나이가 5의 배수라면
                        for(int d=0; d<8; d++){
                            int dx = i + direction[d][0];
                            int dy = j + direction[d][1];
                            if(dx < 1 || dx > n || dy < 1 || dy > n) continue; //범위 벗어남
                            tree[dx][dy].push_front(1); //나이가 1인 나무들 앞에 넣기
                        }
                    }
                }
            }
            //겨울: 양분 추가
            arr[i][j] += A[i][j]; //가을 코드랑 겹치는게 없으므로 함께 진행해도 ㄱㅊ
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    input();
    while(k--){
        spring_summer();
        autumn_winter();
    }
    //남은 나무 개수
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(tree[i][j].size() > 0) {
                answer += tree[i][j].size();
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
