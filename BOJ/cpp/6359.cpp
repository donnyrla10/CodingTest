#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    bool room[10001];
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        for(int i=1; i<=n; i++) room[i] = true; //1round 문 모두 열린 상태
        
        for(int i=2; i<=n; i++){ //매 round
            for(int j=1; j<=n; j++){ //각 room
                if(room[i*j]) room[i*j] = false;
                else          room[i*j] = true;
            }
        }
        
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(room[i]) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
