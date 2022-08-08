#include <iostream>
#include <string>
#include <vector>
using namespace std;
int ans = 0;

int calculate(int op1, int op2, int way){
    if(way == 0) return op1+op2; //+
    return op1-op2;
}

void DFS(int cnt, int k, int target, int value, vector<int> numbers){
    if(cnt == k){
        if(target == value) ans++;
        return;
    }
    DFS(cnt+1, k, target, calculate(value, numbers[cnt], 0), numbers);
    DFS(cnt+1, k, target, calculate(value, numbers[cnt], 1), numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(0, numbers.size(), target, 0, numbers);
    answer = ans;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution({1,1,1,1,1}, 3) << '\n';
    cout << solution({4,1,2,1}, 4) << '\n';
    return 0;
}
