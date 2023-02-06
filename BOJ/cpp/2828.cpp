#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, j;
    int result = 0;
    cin >> n >> m >> j;
    int start = 1;
    int end = m;
    for(int i=1; i<=j; i++){
        int apple;
        cin >> apple;
        bool flag = false;
        while(!flag){
            if(start <= apple && apple <= end) flag = true;
            else if(start > apple){ //바구니가 사과보다 오른쪽에 있는 경우
                start--; end--; result++;
            }else { //바구니가 사과보다 왼쪽에 있는 경우
                start++; end++; result++;
            }
        }
    }
    cout << result << '\n';
    return 0;
}
