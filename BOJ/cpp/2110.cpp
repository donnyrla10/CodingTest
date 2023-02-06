//거리(d)일 때, 공유기 c개를 설치할 수 있는가? -> 최대 거리(D)구하기

#include <iostream>
#include <algorithm>
#define num 200002
using namespace std;
int n, house[num], c;

void input(){
    cin >> n >> c;
    for(int i=0; i<n; i++) cin >> house[i];
}

bool cal(int d){
    int cnt = 1, pos = house[0];
    for(int i=1; i<n; i++){
        if(house[i] - pos < d) continue;
        pos = house[i];
        cnt++;
    }
    return cnt >= c; //d 거리를 두고 c개 이상의 공유기를 설치할 수 있으면 true
}

void solution(){
    sort(house, house+n);
    int L = 0, R = house[n-1] - house[0], answer = 0;
    while(L <= R){
        int mid = (L+R)/2;
        if(cal(mid)){
            answer = mid;
            L = mid + 1;
        }else{
            R = mid - 1;
        }
    }
    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
