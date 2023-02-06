#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, n, limit = 210, time = 0;
    cin >> k >> n; //폭탄들고있는 사람 번호 k, 질문의 개수 n

    for(int i=0; i<n; i++){
        int t; char z;
        cin >> t >> z;

        time += t; //시간 추가
        if(time >= limit) break; //폭탄 터짐
        if(z == 'T'){ //정답이면 다음 사람에게 폭탄 넘기기
            k++;
            if(k==9) k = 1;
        }
    }
    cout << k << '\n';
    return 0;
}
