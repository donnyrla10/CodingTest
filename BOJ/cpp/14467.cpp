#include <iostream>
#include <vector>
using namespace std;
int n, arr[101], ans=0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) arr[i] = -1; //-1로 초기화
    
    for(int i=1; i<=n; i++){
        int cow, pos;
        cin >> cow >> pos;
        
        if(arr[cow] == -1){ //한번도 들어오지 않은 경우
            arr[cow] = pos;
        }else if(arr[cow] != -1 && arr[cow] != pos){ //들어온 적 있고 다른 방향이면
            arr[cow] = pos;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
