#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    deque<pair<int, int>> dq; //input index, value
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        dq.push_back({i, a});
    }
    
    while(!dq.empty()){
        //pop-push하면서 맨 앞으로 터트릴 풍선 등장
        cout << dq.front().first + 1  << ' '; //터트릴 풍선 인덱스 출력
        int n = dq.front().second;
        dq.pop_front(); //맨 앞 원소 없앰
        
        if(dq.empty()) return 0; //위에서 맨 앞 원소를 없앴으므로 empty 였는지 확인하기
        
        if(n > 0){ //양수면 오른쪽으로 이동
            for(int i=0; i<n-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{ //음수면 왼쪽으로 이동
            for(int i=0; i<-n; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    
    return 0;
}
