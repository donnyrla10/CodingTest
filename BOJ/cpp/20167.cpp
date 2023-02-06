//먹이가 n개 일렬로 나열된 나뭇가지를 오른쪽으로 기어가려고 한다.
//시작하는 순간, 애벌레가 0의 위치게 있고, i번째 먹이는 오른쪽으로 i초 기어가야 도달할 수 있다.
//매초 1만큼 오른쪽으로 무조건 진행
//한번 먹이를 먹기 시작하면 연속으로 먹어야하고, 최소 만족도 k 이상되거나 더이상 먹을 먹이가 없을 때, 멈춘다.
//최소 만족도 이상이 되면 k를 초과한 만큼 탈피 에너지를 축적.
//직 후에 애벌레의 만족도는 다시 0이 되고 먹이를 먹을 수 있게 된다.

#include <algorithm>
#include <iostream>
#include <queue>
#define num 22
using namespace std;
int n, k, food[num], ans;

void input(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> food[i];
}

void solution(int x, int energy){
    int sum = 0;
    if(x > n){ //먹을 먹이가 없는 경우, return
        ans = max(ans, energy);
        return;
    }
    
    //x번 먹이를 먹는 경우 (연속으로 먹어야됨)
    for(int i=x; i<=n; i++){
        sum += food[i]; //누적만족도 계산
        if(sum >= k){   //누적만족도 >= 최소만족도 : 탈피에너지로 초과된 값을 업데이트하고, 다음 먹이로 넘어간다.
            solution(i+1, energy + sum - k);
            break;
        }
    }
    
    //x번 먹이를 먹지 않는 경우 (이번 먹이는 먹지 않고 다음으로 넘어간다)
    solution(x+1, energy);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution(1, 0);
    cout << ans << '\n';
    return 0;
}
