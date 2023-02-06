#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
using namespace std;


int n, w, L, ans = 0;
int bridge[1001]; //다리 위 무게 칸
queue<int> truck; //지나갈 트럭들

//모든 트럭이 지나갔는지 체크
bool Done(){
    for(int i=0; i<w; i++) if(bridge[i]) return false; //안에 값이 있으면 아직 트럭이 있는 것
    return true;
}

int calculateWeight(){
    int sum = 0;
    for(int i=0; i<w; i++) sum += bridge[i];
    return sum;
}

void moveTruck(){
    for(int i=0; i<w-1; i++) bridge[i] = bridge[i+1];
    bridge[w-1] = 0; //0으로 바꿔줘야 다리 위 무게 계산시 0을 더할 수 있음
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w >> L;
    while(n--){
        int i;
        cin >> i;
        truck.push(i);
    }
    
    do {
        //1. 다리 위 weight 계산
        int weight = calculateWeight();
        //다리 위 무게가 괜찮다면...
        if(weight <= L){
            //2. 앞에 트럭 앞으로 땡기기 (트럭 이동)
            weight -= bridge[0]; //맨 앞 트럭 무게 빼기
            moveTruck();
            if(!truck.empty() && weight + truck.front() <= L) { //3. 남은 트럭이 있고, 이번 트럭이 추가되어도 다리가 견딜 수 있다면
                bridge[w-1] = truck.front();
                truck.pop();
            }
        }
        ++ans;
    }while(Done());
    
    cout << ans << '\n';
    return 0;
}
