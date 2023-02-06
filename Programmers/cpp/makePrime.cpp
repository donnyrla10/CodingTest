#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
bool visited[51];

bool checkPrime(int n){
    if(n <= 1) return false;
    if(n == 2) return true;

    //만약에 나눴는데 0이 나오면 소수 아님
    for (int j=2; j<n; j++)
        if (n % j == 0)
            return false;
    return true;
}

void rf(vector<int> n, int k, int s, int sum){
    if(k == 3){
        if(checkPrime(sum)) cnt++;
        return;
    }
    
    for(int i=s; i<n.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            rf(n, k+1, i+1, sum+n[i]);
            visited[i] = false;
        }
    }
}

int solution(vector<int> nums) {
    int answer = -1;
    rf(nums, 0, 0, 0);
    answer = cnt;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution({1, 2, 3, 4}) << '\n';
    cout << solution({1, 2, 7, 6, 4}) << '\n';
    return 0;
}

