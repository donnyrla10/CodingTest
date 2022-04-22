#include <iostream>
using namespace std;
int n, m, l;
int person[52];

void solution(){
    int answer = 0;
    int ball = 1;
    person[1] = 1; //1번 사람이 먼저 공을 받는다.

    while(person[ball] != m){
        answer++;
        if(person[ball] % 2 == 0){ //공을 받은 횟수가 짝수라면
            ball = (n+(ball-l))%n;
        }else{  //공을 받은 횟수가 홀수라면
            ball = (ball+l)%n;
        }
        person[ball]++;
    }
    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> l;
    solution();
    return 0;
}
