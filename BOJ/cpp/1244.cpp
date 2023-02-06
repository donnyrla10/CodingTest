#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool _switch[101];
    int n, t;
    //남학생은 스위치 번호가 자기가 받은 수의 배수이면, 그 스위치의 상태를 바꾼다.
    //여학생은 자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간을 찾아서 그 구간에 속한 스위치의 상태를 모두 바꾼다. 구간에 속한 스위치 개수는 항상 홀수
    
    cin >> n;
    for(int i=1; i<=n; i++) cin >> _switch[i];
    cin >> t;
    while(t--){
        int gender, number;
        cin >> gender >> number;
        
        if(gender==1){ //남자
            for(int i=1; i<=n; i++){
                if(i%number==0) _switch[i] = !_switch[i];
            }
        }else{ //여자
            _switch[number] = !_switch[number];
            for(int i=1; _switch[number-i] == _switch[number+i]; i++){
                if(number-i <= 0 || number+i > n) break; //범위를 벗어난 경우
                _switch[number-i] = !_switch[number-i];
                _switch[number+i] = !_switch[number+i];
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        cout << _switch[i] << ' ';
        if(i%20==0) cout << '\n';
    }
    cout << '\n';
    
    return 0;
}
