#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
#include <string>
#include <list>
using namespace std;

//왼쪽에서 오른쪽으로, 오른쪽에서 왼쪽으로
//중앙의 물을 먼저 먹는 선수가 승리
//먹는 음식의 종류와 양이 같고, 음식 먹는 순서도 같아야 한다.
//칼로리가 낮은 음식을 먼저 먹을 수 있게 배치.

string solution(vector<int> food) {
    string front = "";
    string back = "";
    for(int i=1; i<food.size(); i++){
        int n = food[i]/2;
        while(n--){
            front += to_string(i);
            back = to_string(i) + back;
        }
    }
    return front + "0" + back;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({1, 7, 1, 2}) << '\n';
    return 0;
}
