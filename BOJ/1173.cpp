#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, M, t, r;
    cin >> n >> m >> M >> t >> r;
    
    int x = m, et = 0, time = 0;
    
    if(x+t>M && x-r<m){ //n등분할 수 없는 경우
        cout << "-1\n";
    }else{
        while(et != n){ //운동시간 N분이 되면 끝내고 시간 출력
            if(x+t <= M){ //운동 가능
                x = x+t;
                et++;
            }else{ //운동 불가 -> 휴식하기
                x = x-r < m ? m : x-r;
            }
            time++;
        }
        cout << time << '\n';
    }
    return 0;
}

